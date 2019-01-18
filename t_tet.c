/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_tet.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 12:29:47 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/05 16:50:38 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			ft_check_tet_fit(t_tet *tet, char *map, size_t dim, size_t point)
{
	int		i;
	char	*tet_shape;

	tet_shape = tet->map;
	i = 0;
	if (point % dim == 0 && tet_shape[0] == '.')
		return (0);
	while (tet_shape[i] == '.' && point % dim != 0)
	{
		point--;
		i++;
	}
	if (point / dim + tet->y > dim || point % dim + tet->x > dim)
		return (0);
	i = 0;
	while (i < tet->x * tet->y)
	{
		if (i != 0 && i % tet->x == 0)
			point = point + dim - tet->x;
		if (tet_shape[i] != '.' && map[point] != '.')
			return (0);
		i++;
		point++;
	}
	return (1);
}

void		ft_place_tet(t_tet *tet, char *map, size_t dim, size_t point)
{
	int		x;
	int		y;
	char	*tet_shape;

	y = 0;
	tet_shape = tet->map;
	x = 0;
	while (point % dim != 0 && tet_shape[x] == '.')
	{
		point--;
		x++;
	}
	while (y < tet->y)
	{
		x = 0;
		while (x < tet->x)
		{
			if (tet_shape[y * tet->x + x] != '.')
				map[y * dim + point + x] = tet_shape[y * tet->x + x];
			x++;
		}
		y++;
	}
	tet->start = point;
}

void		ft_rem_tet(t_tet *tet, char *map, size_t dim)
{
	int		x;
	int		y;
	char	*tet_shape;

	y = 0;
	tet_shape = tet->map;
	while (y < tet->y)
	{
		x = 0;
		while (x < tet->x)
		{
			if (tet_shape[y * tet->x + x] != '.')
			{
				map[tet->start + y * dim + x] = '.';
			}
			x++;
		}
		y++;
	}
}
