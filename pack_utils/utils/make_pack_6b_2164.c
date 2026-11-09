/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_2164.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_2164(char *perm_label)
{
	if (perm_label[4] == '3')
		return ("pb,pb,ss,pb,sa,pb,ss,pb,pb");
	if (perm_label[4] == '5')
		return ("pb,pb,pb,rr,ss,pb,rra,pb,pb,rrb");
	return (NULL);
}
