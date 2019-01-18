/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 09:10:31 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/05 17:11:23 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int			checkchar(int i, char *map)
{
	int		ret;

	if (map[i] != '#')
		return (checkchar(i + 1, map));
	map[i] = '0';
	ret = 1;
	if (i / 5 != 0 && map[i - 5] == '#')
		ret += checkchar(i - 5, map);
	if (i / 5 != 3 && map[i + 5] == '#')
		ret += checkchar(i + 5, map);
	if (i % 5 != 0 && map[i - 1] == '#')
		ret += checkchar(i - 1, map);
	if (i % 5 != 3 && map[i + 1] == '#')
		ret += checkchar(i + 1, map);
	return (ret);
}

int			readtet(int *min, int *max, char **map)
{
	int		blocks;
	int		i;

	i = 0;
	blocks = 0;
	while (i < 21 && *(*map + i) != '\0')
	{
		if (*(*map + i) == '#')
		{
			*min = (blocks == 0) ? i : *min;
			*max = (blocks == 0) ? i : *max;
			blocks++;
			*min = (*min % 5 > i % 5) ? *min - (*min % 5 - i % 5) : *min;
			*max = (*max % 5 < i % 5) ? *max + (i % 5 - *max % 5) : *max;
			*max = (*max / 5 < i / 5) ? *max + 5 : *max;
		}
		if ((*(*map + i) != '.' && *(*map + i) != '#' &&
					*(*map + i) != '\n') || blocks > 4)
			return (-1);
		if (*(*map + i) == '\n' && i != 20 && i % 5 != 4)
			return (-1);
		i++;
	}
	return (blocks != 4 || checkchar(*min, *map) != 4) ? -1 : 0;
}

char		*remap(char **map, int *x, int *y, char c)
{
	int		i;
	int		j;
	char	*newmap;

	i = *x;
	*x = *y % 5 - i % 5 + 1;
	*y = *y / 5 - i / 5 + 1;
	j = 0;
	if ((newmap = ft_strnew(*x * *y)) == NULL)
		return (NULL);
	while (j < *x * *y)
	{
		if (j != 0 && j % *x == 0)
			i = i - *x + 5;
		if (*(*map + i) == '0')
			newmap[j] = c;
		else
			newmap[j] = '.';
		j++;
		i++;
	}
	return (newmap);
}

t_list		*newtet(char **map, char c)
{
	t_tet	newtet;

	newtet.c = c;
	if (readtet(&(newtet.x), &(newtet.y), map) == -1)
		return (NULL);
	newtet.map = remap(map, &(newtet.x), &(newtet.y), c);
	ft_bzero(*map, 21);
	return (ft_lstnew(&newtet, sizeof(t_tet)));
}

t_list		*validate(int fd, size_t *size, char c)
{
	t_list	*tetrs;
	t_list	*tet;
	char	*map;
	int		ret;

	tetrs = NULL;
	if ((map = ft_strnew(21)) == NULL)
		return (NULL);
	while (c <= 'Z')
	{
		if ((ret = read(fd, map, 21)) < 0
				|| (tet = newtet(&map, c)) == NULL)
			break ;
		ft_lstpushback(&tetrs, tet);
		if (ret == 20)
		{
			*size = 4 * (c - 64);
			free(map);
			return (tetrs);
		}
		c++;
	}
	free(map);
	ft_lstdel(&tetrs, &deltet);
	return (NULL);
}
