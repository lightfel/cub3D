/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 23:46:28 by nhikaru           #+#    #+#             */
/*   Updated: 2020/10/19 23:50:19 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	slen;
	size_t	i;

	if (s == NULL)
		return (NULL);
	slen = ft_strlen((char *)s);
	if (len == 0 || slen <= start)
		return (ft_strdup(""));
	else if (slen - start < len)
		substr = ft_strdup(&s[start]);
	else
	{
		substr = malloc(sizeof(char) * (len + 1));
		if (substr == NULL)
			return (NULL);
		i = 0;
		while (i < len)
		{
			substr[i] = s[start + i];
			i++;
		}
		substr[i] = '\0';
	}
	return (substr);
}
