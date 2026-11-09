/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_6125.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_6125(char *perm_label)
{
	if (perm_label[4] == '3')
		return ("ra,pb,pb,pb,rb,pb,pb,rrr,pb");
	if (perm_label[4] == '4')
		return ("ra,pb,pb,pb,sa,rb,pb,pb,rrr,pb");
	return (NULL);
}
