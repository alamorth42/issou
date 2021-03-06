/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bihattay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 03:36:36 by bihattay          #+#    #+#             */
/*   Updated: 2021/09/29 03:36:46 by bihattay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int range_is_sorted(int *range, int size)
{
  int   i;

  i = 0;
  while (++i < size)
    if (range[i - 1] > range[i])
      return (0);
  return (1);
}
