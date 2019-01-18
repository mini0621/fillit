/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_tet.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 22:04:17 by mnishimo          #+#    #+#             */
/*   Updated: 2018/12/22 20:42:43 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	deltet(void *content, size_t size)
{
	t_tet	*tet;

	size++;
	tet = (t_tet *)content;
	if (tet->map != NULL)
		free(tet->map);
	free(tet);
}
