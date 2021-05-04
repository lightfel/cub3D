/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 21:16:42 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/04 05:24:07 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	i;

	srclen = ft_strlen((char *)src);
	if (dstsize == 0)
		return (srclen);
	i = 0;
	if (dstsize < srclen + 1)
	{
		while (i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
	}
	else
	{
		while (src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
	}
	dst[i] = '\0';
	return (srclen);
}
