/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 10:11:02 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/05 16:52:14 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_gen_n_point(size_t *point, char *map, size_t len)
{
	size_t		i;

	i = *point + 1;
	while (i < len && map[i] != '.')
		i++;
	if (i == len)
		return (-1);
	*point = i;
	return (0);
}

int				ft_solve_a_square(char *map, t_list *block,
				size_t start, size_t dim)
{
	t_tet		*tet;
	int			found;

	if (!block)
		return (1);
	found = 0;
	tet = (t_tet*)(block->content);
	while (found == 0)
	{
		if ((found = ft_check_tet_fit(tet, map, dim, start)) == 0
				&& ft_gen_n_point(&start, map, dim * dim) < 0)
			return (0);
		else if (found != 0)
		{
			ft_place_tet(tet, map, dim, start);
			if ((found = ft_solve_a_square(map, block->next, 0, dim)) == 0)
			{
				ft_rem_tet(tet, map, dim);
				if (ft_gen_n_point(&start, map, dim * dim) < 0)
					return (0);
			}
		}
	}
	return (1);
}

int				ft_solve_squares(t_list *tet_list, size_t first_sol_size)
{
	char		*square;
	size_t		dim;
	size_t		len;

	dim = ft_closesqrt(first_sol_size);
	len = dim * dim * 2;
	if (!(square = ft_strnew(len)))
		return (0);
	ft_memset(square, '.', len);
	while ((ft_solve_a_square(square, tet_list, 0, dim) == 0))
	{
		dim++;
		if (len <= dim * dim)
		{
			free(square);
			if (!(square = ft_strnew(len + SOL_PLUS_SIZE)))
				return (0);
			len = len + SOL_PLUS_SIZE;
		}
		ft_memset(square, '.', dim * dim);
	}
	ft_print_square(square, dim);
	free(square);
	return (1);
}
