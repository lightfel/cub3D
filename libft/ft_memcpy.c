/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 00:33:15 by nhikaru           #+#    #+#             */
/*   Updated: 2020/10/18 03:29:05 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*cdst;
	const unsigned char	*csrc;
	size_t				i;

	cdst = dst;
	csrc = src;
	i = 0;
	if (dst != src)
	{
		while (i < n)
		{
			cdst[i] = csrc[i];
			i++;
		}
	}
	return (dst);
}
