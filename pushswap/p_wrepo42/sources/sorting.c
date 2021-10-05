/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamorth <alamorth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 03:40:18 by bihattay          #+#    #+#             */
/*   Updated: 2021/10/05 09:17:34 by alamorth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_piles(t_pile *pile, t_pile *pile2)
{
	int i = -1;

	printf("presentation des piles\n");
	while (++i < pile->size)
		printf("%4d | %d\n", (pile->nbr)[i], (pile2->nbr)[i]);
}

static void	setup_sort(int *pos, int *max, int *len_displayed)
{
	*pos = 0;
	*max = 0;
	*len_displayed = 0;
}

void	twentyfive(t_pile *pile_a, t_pile *pile_b, int len_displayed, int size)
{
	int		max;
	int		pos;
	int		ret;

	max = 0;
	pos = 0;
	ret = 0;
	while (!range_is_sorted(pile_a->nbr, pile_a->size)
		&& size - ret > 1)
	{
		write(2, "A", 1);
		quicksort(pile_a, pile_b, len_displayed, ret);
		write(2, "B", 1);
		len_displayed = insertsort_basic(pile_b, pile_a, &pos, &max);
		write(2, "C", 1);
		ret += len_displayed;
		sort_three(pile_b, 2);
		write(2, "D", 1);
		repush(pile_a, pile_b);
		write(2, "E", 1);
		print_piles(pile_a, pile_b);
	}
	write(2, "sortie while", 13);
	rev_rotate(pile_a, pile_a->identifier);
	if (pile_a->nbr[0] > pile_a->nbr[1])
		swap(pile_a, 1);
	rev_rotate(pile_a, pile_a->identifier);
	if (pile_a->nbr[0] > pile_a->nbr[1])
		swap(pile_a, 1);

	print_piles(pile_a, pile_b);
}

void	sort_algo(t_pile *pile_a, t_pile *pile_b)
{
	int		pos;
	int		max;
	int		len_displayed;
	int		size;

	setup_sort(&pos, &max, &len_displayed);
	size = pile_a->size;
	if (range_is_sorted(pile_a->nbr, pile_a->size))
		return ;
	if (pile_a->size > 10)
		twentyfive(pile_a, pile_b, len_displayed, size);
	else
		insertsort_basic(pile_a, pile_b, &pos, &max);
	sort_three(pile_a, 1);
	repush(pile_a, pile_b);
}

int	insertsort_basic(t_pile *p_a, t_pile *p_b, int *pos, int *target)
{
	int		ret;

	ret = 0;
	while (p_a->size > 3)
	{
		if (p_a->identifier == 1)
			*pos = find_smaller(*p_a, target);
		else
			*pos = find_bigger(*p_a, target);
		if (*target == (p_a->nbr)[0])
			ret += push(p_a, p_b, p_b->identifier);
		else if (*pos < ((p_a->size) / 2))
			rotate(p_a, p_a->identifier);
		else
			rev_rotate(p_a, p_a->identifier);
	}
	return (ret + 3);
}
