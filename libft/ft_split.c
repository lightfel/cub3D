/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 03:19:21 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/04 05:24:31 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_strnum(const char *s, char c)
{
	size_t	i;
	size_t	strnum;

	if (c == '\0')
	{
		if (*s == '\0')
			return (0);
		return (1);
	}
	i = 0;
	strnum = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			strnum++;
			while (s[i] != c && s[i] != '\0')
				i++;
			continue ;
		}
		i++;
	}
	return (strnum);
}

static int	split_strlen(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static void	*all_free(char **strarray, int i)
{
	int	j;

	j = 0;
	while (j <= i)
	{
		free(strarray[i]);
		j++;
	}
	free((void *)strarray);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**strarray;
	int		i;
	int		strnum;

	if (s == NULL)
		return (NULL);
	strnum = get_strnum(s, c);
	strarray = malloc(sizeof(char *) * (strnum + 1));
	if (strarray == NULL)
		return (NULL);
	i = 0;
	while (i < strnum)
	{
		while (*s != '\0' && *s == c)
			s++;
		strarray[i] = malloc(sizeof(char) * (split_strlen(s, c) + 1));
		if (strarray[i] == NULL)
			return (all_free(strarray, i));
		ft_strlcpy(strarray[i], s, split_strlen(s, c) + 1);
		s += (split_strlen(s, c) + 1);
		i++;
	}
	strarray[i] = NULL;
	return (strarray);
}
