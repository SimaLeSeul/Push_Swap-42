/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_6b_4362.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_6b_4362(char *perm_label)
{
	if (perm_label[4] == '1')
		return ("ra,pb,rr,pb,pb,rra,ss,rrr,pb,pb,pb");
	if (perm_label[4] == '5')
		return ("ra,pb,rr,pb,sa,pb,rra,ss,rrr,pb,pb,pb");
	return (NULL);
}
