/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_5a_135.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_5a_135(char *perm_label)
{
	if (perm_label[3] == '2')
		return ("ra,sa,pb,sa,ra,ra,ra,pa,ra");
	if (perm_label[3] == '4')
		return ("ra,pb,pb,ss,ra,pa,ra,ra,pa,ra");
	return (NULL);
}
