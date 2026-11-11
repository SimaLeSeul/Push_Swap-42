/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_5a_251.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_5a_251(char *perm_label)
{
	if (perm_label[3] == '3')
		return ("sa,pb,sa,ra,ra,ra,ra,pa,ra");
	if (perm_label[3] == '4')
		return ("sa,pb,sa,ra,ra,sa,ra,ra,pa,ra");
	return (NULL);
}
