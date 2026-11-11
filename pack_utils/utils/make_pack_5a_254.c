/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_5a_254.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_5a_254(char *perm_label)
{
	if (perm_label[3] == '1')
		return ("pb,pb,sa,ra,ss,pa,ra,ra,ra,pa,ra");
	if (perm_label[3] == '3')
		return ("sa,pb,pb,pb,ss,ra,pa,ra,ra,pa,ra,pa,ra");
	return (NULL);
}
