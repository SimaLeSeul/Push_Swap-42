# Push Swap — passer des tableaux aux listes circulaires

Ce document explique la migration des piles `a` et `b` vers des listes
doublement chaînées circulaires. Il présente le changement de raisonnement,
les modifications du code et les tests qui permettent de les vérifier.

Le dépôt contient actuellement le parsing, la gestion de la mémoire et les onze
opérations de manipulation. Il ne contient pas encore de `main`, de `Makefile`,
d'algorithme de tri ni de programme `checker`. Les exemples ci-dessous expliquent
le socle disponible ; ils ne décrivent pas un exécutable de tri déjà terminé.

## 1. Le changement de point de vue

### Avant : une pile était une portion de tableau

L'ancien état contenait deux tableaux et trois compteurs :

```c
int     *a;
int     *b;
size_t  pa;
size_t  pb;
size_t  tlen;
```

`pa` et `pb` indiquaient le nombre d'éléments utilisés dans chaque tableau.
`tlen` représentait le nombre total initial d'éléments et servait de capacité.
Le sommet se trouvait à l'indice `0`.

Pour la pile `3 8 1`, on raisonnait ainsi :

```text
indice :  0   1   2
valeur : [3] [8] [1]
          ↑
        sommet
```

Retirer le sommet imposait de décaler les valeurs suivantes. Ajouter un sommet
imposait de faire de la place à l'indice `0`. Une rotation sauvegardait une
valeur, décalait les autres, puis réinsérait la valeur sauvegardée.

Les positions étaient donc matérialisées par des cases de tableau : pour changer
l'ordre, les opérations copiaient des entiers entre ces cases.

### Maintenant : une pile est une boucle avec un point de départ

Chaque entier est placé dans un maillon alloué séparément. Le maillon connaît
son suivant et son précédent. La pile conserve uniquement son sommet et sa taille.

```text
             top
              ↓
             [3] ⇄ [8] ⇄ [1]

next : 3 → 8 → 1 → 3 → ...
prev : 3 → 1 → 8 → 3 → ...
```

L'ordre logique se lit en suivant `next` à partir de `top`, pendant exactement
`size` maillons. Le dernier élément est immédiatement accessible par
`top->prev`.

Les maillons n'ont pas besoin d'être voisins en mémoire. Leurs liens définissent
l'ordre. Un push transfère un maillon entre les deux piles ; une rotation change
seulement le point de départ de lecture de la boucle.

Par exemple, après `ra`, la boucle physique reste la même :

```text
Avant : top → 3 ; lecture : 3 8 1
Après : top → 8 ; lecture : 8 1 3
```

Cette distinction entre la boucle et son sommet est le principal changement
de raisonnement. Le sommet fait partie de la représentation de l'ordre.

Le swap constitue un choix particulier de cette version : il échange les valeurs
des deux premiers maillons, sans déplacer les maillons eux-mêmes.

## 2. Les structures et leurs règles — `push_swap.h`

### Trois niveaux distincts

| Type | Champs | Rôle |
| --- | --- | --- |
| `t_node` | `value`, `next`, `prev` | Stocker un entier et les deux liens |
| `t_stack` | `top`, `size` | Décrire une pile et son point de départ |
| `t_ps_state` | `a`, `b` | Regrouper les deux piles du programme |

Les champs `pa` et `pb` disparaissent : leurs rôles sont repris par `a.size` et
`b.size`. Le champ `tlen` disparaît également, puisqu'il n'y a plus de tableaux
à dimensionner. Le nombre total d'éléments présents vaut `a.size + b.size`.

Les noms des instructions `pa` et `pb` restent utilisés par `op_pa` et `op_pb`.
Il faut les distinguer des anciens champs de taille qui portaient ces noms.

### Les invariants à préserver

Un invariant est une propriété vraie avant et après chaque opération terminée :

- Une pile vide possède `top == NULL` et `size == 0`.
- Une pile d'un élément possède `top->next == top` et `top->prev == top`.
- Dans une pile non vide, `top->prev` désigne le dernier maillon.
- Pour chaque maillon, `node->next->prev == node` et `node->prev->next == node`.
- Un parcours de `size` pas ramène au sommet, sans y revenir plus tôt.
- Chaque maillon appartient à une seule pile.
- Les opérations conservent le nombre total de maillons.

Les fonctions supposent que les piles reçues respectent ces règles. Elles ne
recalculent pas la taille et ne réparent pas une liste déjà corrompue.

### Pourquoi les opérations reçoivent un pointeur

Les signatures passent de :

```c
void op_ra(t_ps_state state);
```

à :

```c
void op_ra(t_ps_state *state);
```

En C, recevoir une structure par valeur crée une copie de ses champs. Dans
l'ancienne version, les pointeurs copiés désignaient encore les mêmes tableaux :
modifier une case était visible par l'appelant. En revanche, modifier `pa` ou
`pb` changeait seulement les compteurs de la copie locale.

Avec les listes, changer `top` ou `size` doit modifier la vraie pile. Les opérations
reçoivent donc l'adresse de l'état et transmettent `&state->a` ou `&state->b` aux
fonctions internes. Modifier `stack->top` agit ainsi sur le champ de l'appelant.

Les prototypes de création, de nettoyage et de parsing ont aussi été adaptés
dans le header. Les appelants doivent utiliser les nouvelles signatures.

## 3. Créer, ajouter et libérer les maillons — nouveau `stack.c`

### `node_new(int value)`

Cette fonction alloue un seul `t_node`, enregistre sa valeur et initialise ses
deux liens vers lui-même. Un maillon nouvellement créé constitue donc déjà une
boucle valide d'un élément.

En cas d'échec de `malloc`, elle retourne `NULL`. Elle n'affiche rien et ne quitte
pas le programme. Le parsing décide de la réaction à cet échec, puisqu'il possède
l'état complet à nettoyer.

### `stack_append(t_stack *stack, t_node *node)`

Cette fonction ajoute un maillon en bas de la pile, sans allocation.

Si la pile est vide, elle relie le maillon à lui-même et le définit comme sommet.
Sinon, elle l'insère entre l'ancien dernier et le sommet :

```text
Avant : ... ⇄ dernier ⇄ top
Après : ... ⇄ dernier ⇄ node ⇄ top
```

Les quatre affectations correspondent aux deux liens du nouveau maillon et aux
deux liens de ses voisins :

```c
node->prev = stack->top->prev;
node->next = stack->top;
stack->top->prev->next = node;
stack->top->prev = node;
```

L'ordre des affectations est utile : l'ancien dernier reste accessible par
`top->prev` jusqu'à la mise à jour finale. Dans une pile déjà remplie, `top` ne
change pas. La taille augmente dans les deux cas.

Le maillon doit être nouvellement créé ou avoir été détaché de sa pile précédente.
La fonction ne le retire pas d'une autre pile. Ajouter directement un maillon
encore membre d'une liste corromprait les liens de cette liste.

### `stack_clear(t_stack *stack)`

Un parcours jusqu'à `NULL` ne convient pas à une liste circulaire : les liens
reviennent toujours au départ. Le nettoyage mémorise donc la taille initiale
dans `remaining`, puis libère exactement ce nombre de maillons.

À chaque tour, il sauvegarde `node->next` avant de libérer `node`. Au dernier
tour, le suivant sauvegardé désigne l'ancien sommet déjà libéré ; la boucle
s'arrête sans le déréférencer.

Enfin, `top` est remis à `NULL` et `size` à zéro. Une pile vide peut être nettoyée,
et une pile déjà nettoyée peut l'être à nouveau. Cette fonction libère les
maillons, mais pas la structure `t_stack` elle-même, qui est un champ de l'état.

## 4. Initialisation et sorties — `push_swap.c`

### `str_to_list(void)`

L'ancienne fonction recevait un tableau et une longueur, conservait le tableau
dans `a`, puis allouait un tableau de même capacité pour `b`.

La nouvelle fonction alloue uniquement `t_ps_state` et initialise deux piles
vides. Aucun maillon n'est encore créé et aucune capacité n'est réservée pour `b`.
Les maillons seront créés au fur et à mesure du parsing.

Le nom `str_to_list` a été conservé, mais cette fonction ne convertit désormais
aucune chaîne. Elle sert à créer l'état initial. Si l'allocation de cet état
échoue, elle retourne `NULL` : l'appelant doit vérifier ce résultat.

### `free_state(t_ps_state *state)`

Cette nouvelle fonction nettoie successivement `a` et `b` avec `stack_clear`,
puis libère l'état. Elle accepte `NULL`, reste silencieuse et retourne normalement.
Elle sert donc au nettoyage après une utilisation réussie.

L'état reçu doit avoir été alloué dynamiquement, comme celui renvoyé par
`str_to_list`. Il ne faut pas lui transmettre l'adresse d'une variable locale,
puisqu'elle appelle `free(state)`. Après son appel, le pointeur de l'appelant
désigne une zone libérée : il ne faut plus l'utiliser ni le libérer à nouveau.

### `freexit(t_ps_state *state)`

La sortie sur erreur appelle maintenant `free_state`, écrit exactement `Error\n`
sur stderr avec `write(2, ...)`, puis termine avec `exit(1)`.

Le nettoyage normal et la sortie sur erreur sont donc séparés. Une réussite
n'entraîne plus l'affichage d'une erreur. Un échec pendant le parsing nettoie
tous les maillons déjà enregistrés dans l'état avant de quitter.

## 5. Le parsing — `parser.c` et `parser_utils.c`

### La validation numérique est conservée

`number_len` et `fits_in_int` gardent leur logique. Le signe éventuel doit être
suivi d'un chiffre. Les zéros initiaux sont ignorés pour comparer la longueur
significative à la limite autorisée. Les limites sont `2147483647` pour un nombre
positif et `2147483648` en valeur absolue pour un nombre négatif.

Après les chiffres, seuls la fin de chaîne ou un caractère reconnu par
`is_whitespace` sont acceptés. Des écritures comme `+`, `--1`, `12x`, ainsi que
les valeurs hors limites, déclenchent une erreur.

`ft_atoi.c` n'a pas été modifié pendant cette migration. La conversion intervient
après validation. Son accumulation négative permet de représenter `INT_MIN`
sans construire d'abord l'entier positif `2147483648`, hors limites d'un `int`
sur 32 bits.

### `append_number` construit maintenant la liste

L'ancienne fonction vérifiait la capacité, cherchait un doublon dans un tableau,
puis écrivait `res[count] = value`.

La nouvelle fonction suit ces étapes :

1. Chercher la valeur dans `state->a`.
2. Quitter avec nettoyage si elle existe déjà.
3. Créer un maillon avec `node_new`.
4. Quitter avec nettoyage si l'allocation échoue.
5. Ajouter le maillon en bas de `a` avec `stack_append`.

Le contrôle de capacité disparaît, puisque chaque nombre possède son allocation.
La vérification du doublon précède l'allocation : aucun maillon supplémentaire
n'est créé pour une valeur refusée.

L'ajout en bas préserve l'ordre d'entrée : lire `3`, puis `8`, puis `1` construit
`3 8 1` du sommet vers le bas. Ajouter chaque nombre au sommet aurait inversé
cet ordre.

### `argtoint` utilise la taille de la pile comme référence

La signature devient :

```c
size_t argtoint(const char *s, t_ps_state *state);
```

Les paramètres `res` et `count` disparaissent. La fonction remplit directement
`state->a` et retourne sa taille cumulée. Il n'est plus nécessaire de réinjecter
un compteur retourné lors du traitement de l'argument suivant : l'état conserve
déjà cette information.

La fonction retient la taille au début de l'appel dans `old_count`. Si elle n'a
ajouté aucun nombre, l'argument est refusé. Cela rejette une chaîne vide ou
composée uniquement d'espaces, même si des appels précédents ont déjà rempli `a`.

Les caractères séparateurs reconnus restent l'espace et ceux compris entre
`\t` et `\r` : tabulation, saut de ligne, tabulation verticale, saut de page et
retour chariot. Un espace insécable Unicode n'est pas un séparateur accepté.

### `contains_value` parcourt une pile

La signature passe de `(int *tab, size_t count, int value)` à
`(const t_stack *stack, int value)`.

La fonction part du sommet, compare `node->value`, avance avec `node->next` et
limite le parcours à `stack->size`. Elle renvoie toujours `1` si la valeur est
présente et `0` sinon. Une pile vide entraîne zéro itération.

Le paramètre `const` exprime que la fonction ne modifie pas la structure de pile
reçue. La recherche se contente également de lire les maillons.

Les doublons sont comparés après conversion : `0` et `-0`, ou `1` et `+0001`,
représentent donc la même valeur et sont refusés ensemble. Un doublon situé dans
un argument ultérieur est détecté dans la pile construite par les appels précédents.

## 6. Les swaps — `op_swap.c`

La logique commune est regroupée dans la fonction interne `stack_swap`.
`op_sa` lui transmet `a`, et `op_sb` lui transmet `b`.

Pour une pile d'au moins deux éléments, elle échange `top->value` et
`top->next->value` à l'aide d'un entier temporaire :

```text
Avant sa : a = 3 8 1
Après sa : a = 8 3 1
```

Les adresses des maillons, les liens, le sommet et la taille restent identiques.
Pour zéro ou un élément, la fonction retourne immédiatement.

Ce choix convient parce que chaque maillon ne transporte actuellement qu'un
entier utile au tri. Si un rang ou d'autres métadonnées associés à la valeur sont
ajoutés, il faudra les échanger avec elle pour conserver leur association.

`op_ss` appelle `op_sa`, puis `op_sb`. Chaque pile est traitée indépendamment :
une pile trop petite n'empêche pas l'autre d'être modifiée.

## 7. Les pushes — `op_push.c`

### Une seule fonction de transfert

Les deux anciennes fonctions contenaient des décalages de tableaux similaires.
Elles utilisent maintenant `stack_push(source, destination)`.

Si la source est vide, rien ne change. Sinon, cette fonction mémorise le sommet
dans `node` et le retire de sa boucle :

- S'il était seul, le sommet de la source devient `NULL`.
- Sinon, son précédent et son suivant sont reliés directement entre eux,
  puis son suivant devient le nouveau sommet de la source.

La taille de la source diminue ensuite d'une unité. Le maillon est inséré dans
la destination avec `stack_append`, qui augmente sa taille.

### Pourquoi un ajout en bas peut servir à un push au sommet

Après `stack_append`, le maillon se trouve juste avant le sommet de destination
dans la boucle. Définir ce maillon comme nouveau sommet donne l'ordre voulu :

```text
Destination initiale : top → 8 ; lecture : 8 1
Après append de 3   : top → 8 ; lecture : 8 1 3
Après top = node    : top → 3 ; lecture : 3 8 1
```

La réutilisation de `stack_append` évite de dupliquer les raccordements. Elle
fonctionne aussi si la destination est vide, puisque le maillon devient alors
une boucle d'un élément.

Il n'y a aucune allocation ni libération pendant un push : c'est le même maillon
qui change de pile. La somme des tailles reste constante.

### Correction du sens des instructions

Les directions étaient inversées dans l'ancien code. Elles suivent maintenant
le nom de la pile de destination :

| Fonction | Source | Destination | Exemple |
| --- | --- | --- | --- |
| `op_pa` | `b` | `a` | `a = 8 1`, `b = 3 5` devient `a = 3 8 1`, `b = 5` |
| `op_pb` | `a` | `b` | `a = 3 8 1`, `b = 5` devient `a = 8 1`, `b = 3 5` |

Les anciennes écritures de `-1` dans une case devenue inutilisée disparaissent.
Il n'y a plus de case libre à marquer ; une pile vide est décrite par ses champs,
et `-1` reste une valeur d'entrée ordinaire.

## 8. Les rotations — `op_rotate.c` et `op_revrotate.c`

Chaque fichier contient une fonction interne nommée `stack_rotate`. Ces fonctions
sont `static` : leur nom est limité à leur fichier, ce qui permet ces deux
définitions distinctes.

Dans `op_rotate.c`, la fonction avance le sommet vers `next` si la taille vaut
au moins deux. Dans `op_revrotate.c`, elle le déplace vers `prev`.

| Fonction | Effet | Exemple |
| --- | --- | --- |
| `op_ra` | Avancer le sommet de `a` | `3 8 1` devient `8 1 3` |
| `op_rb` | Avancer le sommet de `b` | `3 8 1` devient `8 1 3` |
| `op_rra` | Reculer le sommet de `a` | `3 8 1` devient `1 3 8` |
| `op_rrb` | Reculer le sommet de `b` | `3 8 1` devient `1 3 8` |

Aucun entier n'est copié, aucun lien n'est réécrit et les tailles restent
identiques. Les boucles de décalage et les variables de sauvegarde de l'ancien
code sont supprimées.

`op_rr` applique `ra` et `rb`. `op_rrr` applique `rra` et `rrb`. Comme pour `ss`,
chaque pile peut évoluer même si l'autre est vide ou ne contient qu'un élément.

## 9. Un moteur silencieux à partager

Les onze fonctions `op_*` manipulent uniquement l'état : elles n'affichent pas
les noms d'instructions et ne tiennent pas de compteur d'instructions.

Le futur programme `push_swap` pourra appeler ce moteur, puis afficher et compter
l'instruction choisie. Le futur `checker` pourra appeler les mêmes opérations
après lecture d'une instruction, sans la réafficher.

Lorsqu'une instruction combinée sera émise, `rr` devra correspondre à une seule
ligne et une seule instruction comptée, même si son implémentation appelle deux
opérations élémentaires. Cette couche d'émission et de comptage reste à écrire.

## 10. Exemple d'utilisation de la nouvelle interface

Le fragment suivant suppose que `push_swap.h` est inclus et qu'il se trouve dans
une fonction appelante :

```c
t_ps_state *state;

state = str_to_list();
if (!state)
    freexit(NULL);
argtoint("3 8", state);
argtoint("1", state);
/* a = 3 8 1 ; b vide */
op_pb(state);
/* a = 8 1 ; b = 3 */
op_pa(state);
/* a = 3 8 1 ; b vide */
op_ra(state);
/* a = 8 1 3 ; b vide */
free_state(state);
```

Ce fragment n'affiche aucune instruction. Il montre aussi que plusieurs appels
au parsing complètent la même pile, et que le nettoyage final utilise
`free_state`, sans quitter sur erreur.

Les fonctions de parsing sont destinées à construire la pile initiale `a`, avant
les opérations de tri. La recherche de doublons porte sur `a` ; elle ne constitue
pas une validation d'ajouts arbitraires après avoir transféré des valeurs dans `b`.

## 11. Les autres fichiers

`flags_handler.c` et `flags_parser.c` ne changent pas de comportement dans cette
migration. Les différences actuellement visibles par rapport au dernier commit
comprennent des en-têtes de style 42 déjà présents avant la conversion des piles.
Ils ne constituent pas une nouvelle logique de traitement des flags.

`is_whitespace` reste partagé par le parsing des nombres et celui des flags.
Les flags connus sont toujours validés ; leur sélection ne configure pas encore
un algorithme de tri dans le socle actuel.

Le dossier `.codex-token-guard/` relève de l'outillage de travail et ne fait pas
partie de la représentation des piles ni du moteur d'opérations.

## 12. Les tests ajoutés

### `tests/test_core.c` : vérifier les valeurs et les liens

Le programme de test utilise un modèle indépendant à base de petits tableaux.
Chaque opération est appliquée au modèle et à l'état réel, puis leurs résultats
sont comparés.

Pour chacune des tailles initiales de zéro à seize éléments, il exécute
10 000 opérations choisies par un générateur pseudo-aléatoire à graine fixe,
soit 170 000 opérations reproductibles. Des vérifications supplémentaires testent
les couples `ra`/`rra`, `sa`/`sa` et `pb`/`pa` avant ces séquences.

Après les opérations des séquences, les contrôles portent sur :

- Les tailles et l'ordre des valeurs par rapport au modèle.
- Les parcours dans les deux sens et la cohérence des liens réciproques.
- Le retour au sommet après exactement le bon nombre de maillons.
- La conservation des adresses des maillons initialement créés.
- L'absence de maillon partagé entre les deux piles ou perdu pendant un transfert.
- La conservation du nombre total de maillons.

Le test vérifie aussi les boucles solitaires créées par `node_new`, le nettoyage
répété d'une pile et l'acceptation de `NULL` par `free_state`.

### `tests/test_alloc.h` : contrôler les allocations

Ce header est injecté uniquement pendant la compilation des tests. Il remplace
les appels à `malloc` et `free` des sources par `test_malloc` et `test_free`.
Le programme de test fournit ces fonctions et y utilise les vrais allocateurs.

Cela permet de compter les allocations encore vivantes et de faire échouer une
allocation précise. Une fonction enregistrée avec `atexit` vérifie qu'aucune
allocation suivie ne subsiste lors d'une sortie normale ou d'un `exit(1)`.

Ce remplacement n'ajoute aucune dépendance à l'allocateur de test dans une
compilation normale des sources.

### `tests/run.py` : compiler et tester le parsing

Le script compile les sources C à la racine avec le programme de test dans un
dossier temporaire, puis exécute les différents cas. Ce dossier est supprimé à
la fin. Les options comprennent `-Wall -Wextra -Werror`, AddressSanitizer et
UndefinedBehaviorSanitizer.

Il vérifie notamment les limites des entiers, les signes, les zéros initiaux,
les séparateurs, les arguments vides, les doublons et les erreurs après une
construction partielle. Il contrôle le code de sortie et les sorties stdout et
stderr, dont le texte exact `Error\n`.

Pour une entrée de quatre nombres, les cinq allocations attendues sont celle
de l'état et celles des quatre maillons. Le script fait échouer chacune de ces
cinq allocations à son tour. Il vérifie ensuite qu'un échec programmé à la sixième
allocation laisse cette entrée réussir, puisqu'elle n'en demande que cinq.

### Lancer les vérifications

Depuis la racine, avec Python 3 et un compilateur C prenant en charge les deux
sanitizers :

```sh
python3 tests/run.py
```

Le compilateur utilisé est `cc` par défaut. Il peut être choisi avec, par exemple :

```sh
CC=clang python3 tests/run.py
```

Pour vérifier la norme des sources de production avec Norminette installé :

```sh
norminette push_swap.h push_swap.c stack.c parser.c parser_utils.c ft_atoi.c \
    op_push.c op_swap.c op_rotate.c op_revrotate.c flags_handler.c flags_parser.c
```

Le passage des tests avec ASan/UBSan, le contrôle des allocations et celui de la
Norminette ont été vérifiés après la migration. Les séquences testées constituent
une validation reproductible ; elles ne remplacent pas le respect des invariants
dans les développements suivants.

Lorsqu'un `main` de production sera ajouté, la sélection des sources dans
`tests/run.py` devra être adaptée : elle inclut actuellement tous les fichiers
`*.c` de la racine, et le programme de test possède déjà son propre `main`.

## 13. Ce que la migration change en performance

| Action | Ancienne représentation | Nouvelle représentation |
| --- | --- | --- |
| Swap | O(1) | O(1) |
| Push | O(n), décalages | O(1), raccordements |
| Rotate | O(n), décalages | O(1), changement de sommet |
| Reverse rotate | O(n), décalages | O(1), changement de sommet |
| Opération combinée | Jusqu'à O(n) | O(1) |
| Recherche d'une valeur | O(n) | O(n) |
| Nettoyage des éléments | Libération des blocs de tableaux | O(n), libération des maillons |

Pour les opérations sur deux piles, `n` représente la quantité d'éléments
concernée. Une opération combinée reste en O(1) dans la nouvelle représentation,
puisqu'elle applique un nombre fixe d'opérations en O(1).

Le parsing peut toujours demander O(n²) comparaisons au total : avant chaque
ajout, il parcourt les valeurs déjà présentes pour détecter un doublon.

La liste utilise aussi deux pointeurs supplémentaires par valeur et une
allocation par maillon, avec le surcoût de l'allocateur. Les tableaux conservent
l'avantage d'un stockage contigu en mémoire.

Enfin, exécuter une instruction plus rapidement ne diminue pas le nombre
d'instructions nécessaires au tri. Les choix d'algorithmes, leur sélection par
les flags, l'émission des instructions, leur comptage et le futur `checker`
constituent les étapes suivantes du projet.
