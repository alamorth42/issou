/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamorth <alamorth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 03:40:18 by bihattay          #+#    #+#             */
/*   Updated: 2021/10/05 09:12:07 by alamorth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	fst_bcle(t_pile *p_a, t_pile *p_b, t_quick_sort *s, unsigned int ret)
{
	int		y2;
	int		pos;
	int		max;

	y2 = p_a->size - ret;
	pos = 0;
	max = 0;
	while (--y2 >= 0 && s->first == 0)
	{
		if ((p_a->nbr)[0] > s->pivot + s->pivot / 2)
			push(p_a, p_b, p_b->identifier);
		else
			rotate(p_a, p_a->identifier);
	}
	if (s->first == 0)
	{
		insertsort_basic(p_b, p_a, &pos, &max);
		sort_three(p_b, 2);
		repush(p_a, p_b);
	}
	if ((p_a->nbr)[0] > s->pivot)
		push(p_a, p_b, p_b->identifier);
	else
		rotate(p_a, p_a->identifier);
}

void	other_boucle(t_pile *pile_a, t_pile *pile_b, int ret, t_quick_sort *s)
{
	if (s->u == 0)
		rev_rotate(pile_a, pile_a->identifier);
	if ((pile_a->nbr)[0] > s->pivot)
	{
		push(pile_a, pile_b, pile_b->identifier);
		s->count = s->count + 1;
	}
	if (s->y >= 1)
		rev_rotate(pile_a, pile_a->identifier);
	else
	{
		s->i = ret + s->count;
		while (s->i < (pile_a->size + pile_b->size))
		{
			write(2, "KO", 2);
			rotate(pile_a, pile_a->identifier);
			s->i = s->i + 1;
		}
	}
}

void	quicksort(t_pile *p_a, t_pile *p_b, unsigned int len, unsigned int ret)
{
	t_quick_sort	structure;

	structure = st_qck_sort(p_a, len, ret);
	while (structure.y >= 0)
	{
		if (len == 0)
		{
			fst_bcle(p_a, p_b, &structure, ret);
			structure.first++;
		}
		else
		{
			other_boucle(p_a, p_b, ret, &structure);
			structure.u += 1;
		}
		write(2, "retour", 6);
		structure.y--;
	}
	write(2, "sortie", 5);
}
