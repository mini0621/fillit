/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 09:11:24 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/07 02:39:08 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define SOL_PLUS_SIZE 25
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct				s_list
{
	void					*content;
	size_t					content_size;
	struct s_list			*next;
}							t_list;

typedef struct				s_coord
{
	int						x;
	int						y;
}							t_coord;

typedef struct				s_tet
{
	char					c;
	char					*map;
	int						x;
	int						y;
	int						start;
}							t_tet;

int							checkchar(int i, char *map);
int							readtet(int *min, int *max, char **map);
char						*remap(char **map, int *x, int *y, char c);
t_list						*newtet(char **map, char c);
t_list						*validate(int fd, size_t *size, char c);
void						ft_print_square(char *square, size_t dim);
int							ft_faults(int flag);
void						deltet(void *content, size_t size);
int							ft_larger(int a, int b);
int							getindex(char *board, t_tet *tet);
int							ft_solve_squares(t_list *tet_list,
							size_t first_sol_size);
int							ft_solve_a_square(char *map, t_list *block,
							size_t start, size_t dim);
int							ft_gen_n_point(size_t *point, char *map,
							size_t len);
void						ft_rem_tet(t_tet *tet, char *map,
							size_t dim);
void						ft_place_tet(t_tet *tet, char *map,
							size_t dim, size_t point);
int							ft_check_tet_fit(t_tet *tet, char *map,
							size_t dim, size_t point);
size_t						ft_tet_xshift(t_tet *tet);
void						*ft_memalloc(size_t size);
void						*ft_memset(void *b, int c, size_t len);
void						ft_putendl(char const *s);
void						ft_putstr(char const *s);
size_t						ft_strlen(const char *s);
void						ft_lstdel(t_list **alst, void (*del)(void*,
							size_t));
char						*ft_strnew(size_t size);
void						ft_bzero(void *s, size_t n);
t_list						*ft_lstnew(void const *content,
							size_t content_size);
void						*ft_memcpy(void *dst, const void *src, size_t n);
void						ft_lstpushback(t_list **alst, t_list *new);
void						ft_putchar(char c);
int							ft_closesqrt(int nb);

#endif
