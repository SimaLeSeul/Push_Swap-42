/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_4b_32.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_4b_32(char *perm_label)
{
	if (perm_label[2] == '1')
		return ("sa,pb,sa,pb,sb,pb,pb");
	if (perm_label[2] == '4')
		return ("sa,pb,pb,rr,pb,sb,rrr,pb");
	return (NULL);
}
