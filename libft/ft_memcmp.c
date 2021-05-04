/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 11:48:38 by nhikaru           #+#    #+#             */
/*   Updated: 2020/10/18 12:31:21 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*cs1;
	const unsigned char	*cs2;
	unsigned char		c1;
	unsigned char		c2;
	size_t				i;

	if (n == 0)
		return (0);
	cs1 = s1;
	cs2 = s2;
	i = 0;
	while (i < n && cs1[i] == cs2[i])
		i++;
	if (i == n)
		i--;
	c1 = cs1[i];
	c2 = cs2[i];
	return (c1 - c2);
}
