/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_5614.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_5614(char *perm_label)
{
	if (perm_label[4] == '2')
		return ("pb,rr,pb,sa,pb,sa,pb,pb,rrr,pb");
	if (perm_label[4] == '3')
		return ("pb,rr,pb,sa,pb,sa,pb,sb,pb,rrr,pb");
	return (NULL);
}
