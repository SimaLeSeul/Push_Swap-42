/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_4532.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_4532(char *perm_label)
{
	if (perm_label[4] == '1')
		return ("pb,ra,rr,sa,pb,pb,rra,pb,rrr,pb,pb");
	if (perm_label[4] == '6')
		return ("pb,ra,rr,pb,sa,pb,sb,rra,pb,rrr,pb,pb");
	return (NULL);
}
