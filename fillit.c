/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 09:58:13 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/06 18:12:57 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	int		fd;
	t_list	*tetrs;
	size_t	size;

	if (argc != 2)
		return (ft_faults(1));
	if ((fd = open(argv[1], O_RDONLY)) < -1)
		return (ft_faults(2));
	if ((tetrs = validate(fd, &size, 'A')) == NULL)
	{
		close(fd);
		return (ft_faults(2));
	}
	close(fd);
	if (!ft_solve_squares(tetrs, size))
		return (ft_faults(2));
	ft_lstdel(&tetrs, &deltet);
	return (0);
}

int			ft_faults(int flag)
{
	if (flag == 1)
		ft_putendl("usage: ./fillit input_file");
	if (flag == 2)
		ft_putendl("error");
	return (1);
}

void		ft_print_square(char *square, size_t dim)
{
	size_t	i;

	i = 0;
	while (i < dim)
	{
		write(1, square + i * dim, dim);
		write(1, "\n", 1);
		i++;
	}
}
