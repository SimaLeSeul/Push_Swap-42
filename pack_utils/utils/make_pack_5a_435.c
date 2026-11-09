/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pack_5a_435.c               :+:      :+:    :+:    #		*/
/*                                                    +:+ +:+         +:+     */
/*   By: jecourto <jecourto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 02:43:43 by jecourto          #+#    #+#             */
/*   Updated: 2026/11/10 02:44:33 by jecourto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*make_pack_5a_435(char *perm_label)
{
	if (perm_label[3] == '1')
		return ("sa,ra,ra,ra,pb,sa,pb,ss,pa,sa,pa");
	if (perm_label[3] == '2')
		return ("sa,ra,ra,ra,sa,pb,sa,pb,ss,pa,sa,pa");
	return (NULL);
}
