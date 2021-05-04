/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:38:36 by nhikaru           #+#    #+#             */
/*   Updated: 2020/10/18 04:14:51 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*cs;
	unsigned char		uc;
	size_t				i;

	cs = s;
	uc = c;
	i = 0;
	while (i < n)
	{
		if (cs[i] == uc)
		{
			return ((void *)&cs[i]);
		}
		i++;
	}
	return (NULL);
}
