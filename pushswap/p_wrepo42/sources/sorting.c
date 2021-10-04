/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamorth <alamorth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 03:40:18 by bihattay          #+#    #+#             */
/*   Updated: 2021/10/01 13:27:45 by alamorth         ###   ########.fr       */
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

void	sort_algo(t_pile *pile_a, t_pile *pile_b)
{
	int		pos;
	int		max;
	int		len_displayed;
	int		size;
	int ret;

	pos = 0;
	ret = 0;
	max = 0;
	len_displayed = 0;
	size = pile_a->size;

	if (range_is_sorted(pile_a->nbr, pile_a->size))
		return ;

	if (pile_a->size > 25)
	{
		while (!range_is_sorted(pile_a->nbr, pile_a->size)
			&& size - ret > 2)
		{
			quicksort(pile_a, pile_b, len_displayed, ret);
			len_displayed = insertsort_basic(pile_b, pile_a, &pos, &max);
			ret += len_displayed;
			sort_three(pile_b, 2);
			repush(pile_a, pile_b);
		}
		rev_rotate(pile_a, pile_a->identifier);
		if (pile_a->nbr[0] > pile_a->nbr[1]) {
			swap(pile_a, 1);
		}
		rev_rotate(pile_a, pile_a->identifier);
		if (pile_a->nbr[0] > pile_a->nbr[1]) {
			swap(pile_a, 1);
		}
	}
	else
		insertsort_basic(pile_a, pile_b, &pos, &max);
		sort_three(pile_a, 1);
		repush(pile_a, pile_b);
}

void first_boucle(t_pile *pile_a, t_pile *pile_b, int pivot, int first, unsigned int ret)
{
		int y2;
		int pos;
		int max;

		y2 = pile_a->size - ret;
		pos = 0;
		max = 0;

		while (--y2 >= 0 && first == 0)
		{
			if ((pile_a->nbr)[0] > pivot + pivot / 2)
				push(pile_a, pile_b, pile_b->identifier);
			else
				rotate(pile_a, pile_a->identifier);
		}
		if (first == 0) {
			insertsort_basic(pile_b, pile_a, &pos, &max);
			sort_three(pile_b, 2);
			repush(pile_a, pile_b);
		}

		if ((pile_a->nbr)[0] > pivot)
			push(pile_a, pile_b, pile_b->identifier);
		else
			rotate(pile_a, pile_a->identifier);
}

void other_boucle(t_pile *pile_a, t_pile *pile_b, int ret, t_quick_sort *structure)
{
	if (structure->u == 0)
		rev_rotate(pile_a, pile_a->identifier);
	if ((pile_a->nbr)[0] > structure->pivot) {
		push(pile_a, pile_b, pile_b->identifier);
		structure->count = structure->count + 1;
	}
	if (structure->y >= 1) {
	rev_rotate(pile_a, pile_a->identifier);
	}
else {
	structure->i = ret + structure->count;
	while (structure->i < (pile_a->size + pile_b->size)) {
						rotate(pile_a, pile_a->identifier);
						structure->i = structure->i + 1;
				}
		}
}

void quicksort(t_pile *pile_a, t_pile *pile_b, unsigned int len, unsigned int ret)
{
	t_quick_sort structure;

	structure = struct_quick_sort(pile_a, len, ret);
	while (structure.y >= 0)
	{
		if (len == 0)
			first_boucle(pile_a, pile_b, structure.pivot, structure.first++, ret);
		else  {
		other_boucle(pile_a, pile_b, ret, &structure);
		structure.u += 1;
		}
		structure.y--;
	}
}

int insertsort_basic(t_pile *p_a, t_pile *p_b, int *pos, int *target)
{
	int ret;

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

void	sort_two(t_pile *pile_a)
{
	int		*tmp;

	tmp = pile_a->nbr;
	if (tmp[0] > tmp[1])
		swap(pile_a, pile_a->identifier);
}

static int	case_three_basic(int a, int b, int c)
{
	if (a < b && b < c)
		return (0);
	else if (a > b && a < c)
		return (1);
	else if (a > b && b > c)
		return (3);
	else if (a > b && b < c && a > c)
		return (3);
	else if (a < b && b > c && a > c)
		return (2);
	else
		return (1);
}

static int	case_three_quicksort(int a, int b, int c)
{
	if (a > b && b > c)
		return (0);
	else if (b > a && a > c)
		return (1);
	else if (c < b && b > a && a < c)
		return (3);
	else if (b < a && c > a)
		return (2);
	else
		return (1);
}

void	sort_three(t_pile *pile, int c)
{
	int		*tmp;
	int		res;
	int		op;

	op = 0;
	tmp = pile->nbr;
	res = 1;
	while (res)
	{
		if (c == 1)
			res = case_three_basic(tmp[0], tmp[1], tmp[2]);
		else
			res = case_three_quicksort(tmp[0], tmp[1], tmp[2]);
		if (res == 1)
			swap(pile, pile->identifier);
		else if (res == 3)
			rotate(pile, pile->identifier);
		else if (res == 2)
			rev_rotate(pile, pile->identifier);
	}
}
