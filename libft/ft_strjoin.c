/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 00:46:00 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/04 05:28:39 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*check_null_sub(const char *s)
{
	char	*nstr;
	size_t	slen;

	slen = ft_strlen((char *)s);
	nstr = malloc(sizeof(char) * (slen + 1));
	if (nstr == NULL)
		return (NULL);
	ft_strlcpy(nstr, s, slen + 1);
	return (nstr);
}

static char	*check_null(const char *s1, const char *s2)
{
	char	*nstr;

	nstr = NULL;
	if (s1 == NULL && s2 == NULL)
	{
		nstr = malloc(sizeof(char));
		if (nstr != NULL)
			*nstr = '\0';
	}
	else if (s1 == NULL)
	{
		nstr = check_null_sub(s2);
	}
	else if (s2 == NULL)
	{
		nstr = check_null_sub(s1);
	}
	return (nstr);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*nstr;
	size_t	s1len;
	size_t	s2len;
	size_t	nstrsize;

	nstr = check_null(s1, s2);
	if (nstr == NULL && s1 != NULL && s2 != NULL)
	{
		s1len = ft_strlen((char *)s1);
		s2len = ft_strlen((char *)s2);
		nstrsize = s1len + s2len + 1;
		nstr = malloc(sizeof(char) * nstrsize);
		if (nstr == NULL)
			return (NULL);
		ft_strlcpy(nstr, s1, nstrsize);
		ft_strlcat(nstr, s2, nstrsize);
	}
	return (nstr);
}
