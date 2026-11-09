/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_1463.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_1463(char *perm_label)
{
	if (perm_label[4] == '2')
		return ("pb,pb,rr,sa,pb,pb,pb,rrr,sb,pb");
	if (perm_label[4] == '5')
		return ("pb,pb,rr,pb,sa,pb,sb,pb,rrr,sb,pb");
	return (NULL);
}
