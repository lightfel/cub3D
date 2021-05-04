/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 01:47:42 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/04 05:30:50 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_pre_trim_num(const char *s1, const char *set)
{
	size_t	i;
	size_t	pre_trim_num;

	i = 0;
	pre_trim_num = 0;
	if (set == NULL)
		return (0);
	while (s1[i] != '\0')
	{
		if (ft_strchr(set, s1[i]) == NULL)
			break ;
		else
			pre_trim_num++;
		i++;
	}
	return (pre_trim_num);
}

static size_t	get_suf_trim_num(const char *s1, const char *set, size_t s1len)
{
	int		i;
	size_t	suf_trim_num;

	i = s1len - 1;
	suf_trim_num = 0;
	if (set == NULL)
		return (0);
	while (i >= 0)
	{
		if (ft_strchr(set, s1[i]) == NULL)
			break ;
		else
			suf_trim_num++;
		i--;
	}
	return (suf_trim_num);
}

static void	trim(const char *s1, char *trimstr,
	size_t pre_trim_num, size_t trimstrlen)
{
	size_t	i;

	i = 0;
	while (i < trimstrlen)
	{
		trimstr[i] = s1[pre_trim_num + i];
		i++;
	}
	trimstr[i] = '\0';
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*trimstr;
	int		trimstrlen;
	size_t	slen;
	size_t	pre_trim_num;
	size_t	suf_trim_num;

	if (s1 == NULL)
		return (ft_strdup(""));
	slen = ft_strlen((char *)s1);
	pre_trim_num = get_pre_trim_num(s1, set);
	suf_trim_num = get_suf_trim_num(s1, set, slen);
	trimstrlen = slen - (pre_trim_num + suf_trim_num);
	if (trimstrlen <= 0)
		return (ft_strdup(""));
	trimstr = malloc(sizeof(char) * (trimstrlen + 1));
	if (trimstr == NULL)
		return (NULL);
	trim(s1, trimstr, pre_trim_num, trimstrlen);
	return (trimstr);
}
