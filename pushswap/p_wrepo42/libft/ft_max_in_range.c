/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_in_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamorth <alamorth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:06:25 by alamorth          #+#    #+#             */
/*   Updated: 2021/10/06 11:33:25 by alamorth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_maxinrange(int *tab, int size)
{
	int		i;
	int		ret;
	int		compare;

	i = -1;
	compare = 0;
	if (tab && *tab)
		ret = tab[0];
	else
		ret = 0;
	while (++i < size)
	{
		if (tab[i] < 0)
			compare = -tab[i];
		else
			compare = tab[i];
		if (ret < compare)
			ret = compare;
	}
	return (ret);
}
