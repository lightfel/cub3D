/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 01:26:57 by nhikaru           #+#    #+#             */
/*   Updated: 2020/10/18 03:23:23 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*cdst;
	const unsigned char	*csrc;
	unsigned char		uc;
	size_t				i;

	cdst = dst;
	csrc = src;
	uc = c;
	i = 0;
	while (i < n)
	{
		if (csrc[i] == uc)
		{
			ft_memcpy(cdst, csrc, i + 1);
			return (dst + i + 1);
		}
		i++;
	}
	ft_memcpy(cdst, csrc, n);
	return (NULL);
}
