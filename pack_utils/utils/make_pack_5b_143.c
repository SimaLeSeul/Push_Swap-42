/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_5b_143.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_5b_143(char *perm_label)
{
	if (perm_label[3] == '2')
		return ("pb,sa,pb,sa,pb,sb,pb,pb");
	if (perm_label[3] == '5')
		return ("pb,sa,pb,pb,rr,pb,sb,rrr,pb");
	return (NULL);
}
