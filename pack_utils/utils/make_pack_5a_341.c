/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_5a_341.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_5a_341(char *perm_label)
{
	if (perm_label[3] == '2')
		return ("pb,sa,ra,sa,ra,pa,ra,ra,ra");
	if (perm_label[3] == '5')
		return ("pb,pb,ra,sa,ra,pa,pa,ra,ra,ra");
	return (NULL);
}
