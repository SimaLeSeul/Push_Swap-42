/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_5a_534.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_5a_534(char *perm_label)
{
	if (perm_label[3] == '1')
		return ("pb,pb,sa,ra,sa,ra,pa,ra,ra,pa,ra");
	if (perm_label[3] == '2')
		return ("pb,pb,pb,sa,ra,ra,pa,pa,ra,ra,pa,ra");
	return (NULL);
}
