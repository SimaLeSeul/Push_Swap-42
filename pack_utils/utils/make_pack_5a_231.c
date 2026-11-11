/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_5a_231.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_5a_231(char *perm_label)
{
	if (perm_label[3] == '4')
		return ("pb,sa,ra,pa,ra,ra,ra,ra");
	if (perm_label[3] == '5')
		return ("pb,sa,ra,pa,ra,ra,sa,ra,ra");
	return (NULL);
}
