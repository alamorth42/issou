/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamorth <alamorth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:02:52 by alamorth          #+#    #+#             */
/*   Updated: 2021/10/07 12:56:51 by alamorth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	adjacent_of_minus(char *str, int index)
{
	int		i;

	i = -1;
	if (index == 0)
		return (ft_isdigit(str[1]));
	while (str[++i])
		;
	if (index == i)
		return (0);
	return (str[index - 1] == ' ' && ft_isdigit(str[index + 1]));
}

char	**parsearg(char **argv, int argc)
{
	int	i;
	int	j;

	i = -1;
	if (argc == 1 || (!ft_isdigit(argv[1][0]) && argv[1][0] != '-'))
		return (NULL);
	if (argc == 2)
	{
		while (argv[1][++i])
			if (!ft_isdigit(argv[1][i]) && argv[1][i] != ' '
			&& !adjacent_of_minus(argv[1], i))
				return (NULL);
		return (ft_strsplit(argv[1], ' '));
	}
	i = 0;
	while (argv[++i])
	{
		j = -1;
		if (argv[i][0] == '-' && ft_strlen(argv[i]) == 1)
			return (NULL);
		while (argv[i][++j])
			if (!(j == 0 && argv[i][0] == '-') && !ft_isdigit(argv[i][j]))
			{
				if (argv[i][j] != ' ')
					return (NULL);
			}
	}
	return (argv + 1);
}
