/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 21:38:13 by nhikaru           #+#    #+#             */
/*   Updated: 2020/10/18 13:52:49 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	s1size;
	char	*s1cp;

	s1size = ft_strlen((char *)s1) + 1;
	s1cp = malloc(sizeof(char) * s1size);
	if (s1cp != NULL)
	{
		ft_strlcpy(s1cp, s1, s1size);
	}
	return (s1cp);
}
