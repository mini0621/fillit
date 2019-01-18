/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 22:10:12 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/07 02:30:20 by mndhlovu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <string.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*ptr;

	ptr = (char *)malloc(size + 1);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, '\0', size + 1);
	return (ptr);
}
