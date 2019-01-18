/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 22:32:41 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/07 02:23:07 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*p1;

	p1 = *alst;
	while (p1 != NULL)
	{
		del(p1->content, p1->content_size);
		*alst = p1->next;
		free(p1);
		p1 = *alst;
	}
	*alst = NULL;
}
