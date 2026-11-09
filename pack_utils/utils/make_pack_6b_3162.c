/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_3162.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_3162(char *perm_label)
{
	if (perm_label[4] == '4')
		return ("pb,pb,ss,pb,ss,pb,sa,pb,pb");
	if (perm_label[4] == '5')
		return ("sa,pb,pb,pb,rb,pb,ss,pb,pb,rrb");
	return (NULL);
}
