/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_5a_451.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_5a_451(char *perm_label)
{
	if (perm_label[3] == '2')
		return ("pb,pb,ra,ra,ra,pa,pa,ra,ra");
	if (perm_label[3] == '3')
		return ("pb,pb,ra,sa,ra,ra,pa,pa,ra,ra");
	return (NULL);
}
