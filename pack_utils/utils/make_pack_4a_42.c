/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_4a_42.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_4a_42(char *perm_label)
{
	if (perm_label[2] == '1')
		return ("pb,sa,ra,ra,ra,pa,ra");
	if (perm_label[2] == '3')
		return ("sa,ra,sa,ra,ra,sa,pb,sa,pa");
	return (NULL);
}
