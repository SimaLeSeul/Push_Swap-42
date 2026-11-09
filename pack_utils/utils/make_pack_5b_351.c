/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_5b_351.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_5b_351(char *perm_label)
{
	if (perm_label[3] == '2')
		return ("pb,sa,pb,ss,pb,ss,pb,pb");
	if (perm_label[3] == '4')
		return ("pb,pb,rb,pb,ss,pb,sb,pb,rrb");
	return (NULL);
}
