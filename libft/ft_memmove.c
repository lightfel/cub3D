/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 01:57:38 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/04 05:24:56 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memmove_sub(unsigned char *dst,
	const unsigned char *src, size_t len)
{
	size_t	i;

	if (dst <= src)
	{
		i = 0;
		while (i < len)
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
	{
		i = len;
		while (i > 0)
		{
			dst[i - 1] = src[i - 1];
			i--;
		}
	}
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == NULL && src == NULL)
		return (NULL);
	return (ft_memmove_sub(dst, src, len));
}
