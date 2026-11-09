/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_4321.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_4321(char *perm_label)
{
	if (perm_label[4] == '5')
		return ("sa,pb,rr,sa,pb,pb,rrr,pb,pb,pb");
	if (perm_label[4] == '6')
		return ("sa,pb,rr,pb,pb,ss,rrr,pb,pb,pb");
	return (NULL);
}
