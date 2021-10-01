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

int find_pivot(t_pile pile, unsigned int len, unsigned int start)
{
  int ret;
  int count;
  unsigned int i;
  unsigned int j;
  int y;

	y = start;
  ret = 0;
  i = 0;
  j = 0;
  //printf("%d len = \n", len);
  //printf("%d start = \n", start);
  while (i < len)
  {
	  count = 0;
	  j = 0;
	  while (j < len){
	  	  if (pile.nbr[i] > pile.nbr[j]) {
				count++;
		  }
		  j++;
	  }
	  if (len % 2 == 1) {
		  if (count == len / 2) {
			  break;
		  }
	  } else {
		  	if (count == len / 2 - 1) {
			  break;
			  }
	  }
	  i++;
	
  }
	//printf("%d pivot = \n", pile.nbr[i]);
  return ((pile.nbr)[i]);
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
