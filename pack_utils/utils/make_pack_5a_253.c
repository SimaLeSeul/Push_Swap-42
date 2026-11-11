/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_5a_253.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_5a_253(char *perm_label)
{
	if (perm_label[3] == '1')
		return ("pb,pb,ss,ra,pa,ra,ra,ra,pa,ra");
	if (perm_label[3] == '4')
		return ("sa,pb,pb,pb,sa,ra,pa,pa,ra,ra,ra,pa,ra");
	return (NULL);
}
