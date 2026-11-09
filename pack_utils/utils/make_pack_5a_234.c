/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_5a_234.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_5a_234(char *perm_label)
{
	if (perm_label[3] == '1')
		return ("ra,ra,ra,sa,ra,sa,pb,sa,pa");
	if (perm_label[3] == '5')
		return ("ra,ra,ra,ra,sa,pb,sa,pa");
	return (NULL);
}
