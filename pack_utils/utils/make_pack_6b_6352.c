/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_6352.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_6352(char *perm_label)
{
	if (perm_label[4] == '1')
		return ("pb,ra,rr,pb,pb,rra,ss,rra,pb,pb,pb,rrb");
	if (perm_label[4] == '4')
		return ("pb,ra,rr,pb,sa,pb,rra,ss,rra,pb,pb,pb,rrb");
	return (NULL);
}
