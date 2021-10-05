/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_elem_in_range.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamorth <alamorth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 03:39:07 by bihattay          #+#    #+#             */
/*   Updated: 2021/10/01 12:55:50 by alamorth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void setup_pivot(int *y, int *ret, int *i, int *j, int start)
{
  *y = start;
  *ret = 0;
  *i = -1;
  *j = -1;
}

void setup_two(int *count, int *j)
{
  *count = 0;
  *j = -1;
}

int find_pivot(t_pile pile, int len, unsigned int start)
{
  int ret;
  int count;
  int i;
  int j;
  int y;

	setup_pivot(&y, &ret, &i, &j, start);
  while (++i < len)
  {
    setup_two(&count, &j);
	  while (++j < len)
    {
	  	  if (pile.nbr[start + i] > pile.nbr[start +j])
				    count++;
	  }
	  if (len % 2 == 1)
    {
		  if (count == len / 2)
			  break;
	  }
    else
		  	if (count == len / 2 - 1)
			     break;
  }
  return ((pile.nbr)[start + i]);
}

int	find_smaller(t_pile pile, int *min)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	*min = (pile.nbr)[0];
	while (++i < pile.size)
		if ((pile.nbr)[i] < *min)
		{
			*min = (pile.nbr)[i];
			ret = i;
		}
	return (ret);
}

int	find_bigger(t_pile pile, int *max)
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	*max = (pile.nbr)[0];
	while (++i < pile.size)
		if ((pile.nbr)[i] > *max)
		{
			*max = (pile.nbr)[i];
			ret = i;
		}
	return (ret);
}
