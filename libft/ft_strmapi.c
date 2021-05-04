/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 15:27:07 by nhikaru           #+#    #+#             */
/*   Updated: 2020/10/18 16:29:41 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*retstr;
	size_t	slen;
	size_t	i;

	if (s == NULL)
	{
		retstr = malloc(sizeof(char));
		if (retstr != NULL)
			*retstr = '\0';
		return (retstr);
	}
	slen = ft_strlen((char *)s);
	retstr = malloc(sizeof(char) * (slen + 1));
	if (retstr == NULL)
		return (NULL);
	i = 0;
	while (i < slen)
	{
		retstr[i] = f(i, s[i]);
		i++;
	}
	retstr[i] = '\0';
	return (retstr);
}
