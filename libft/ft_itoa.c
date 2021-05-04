/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 14:09:25 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/04 05:25:57 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_digit(int n)
{
	size_t	digit;

	if (n <= 0)
		digit = 1;
	else
		digit = 0;
	while (n != 0)
	{
		n /= 10;
		digit++;
	}
	return (digit);
}

static char	*strmin(void)
{
	char	*strmin;

	strmin = malloc(sizeof(char) * 12);
	if (strmin == NULL)
		return (NULL);
	strmin[0] = '-';
	strmin[1] = '2';
	strmin[2] = '1';
	strmin[3] = '4';
	strmin[4] = '7';
	strmin[5] = '4';
	strmin[6] = '8';
	strmin[7] = '3';
	strmin[8] = '6';
	strmin[9] = '4';
	strmin[10] = '8';
	strmin[11] = '\0';
	return (strmin);
}

static char	*ft_itoa_sub(char *strnum, int n, size_t digit)
{
	size_t	i;
	int		mod;

	i = 0;
	if (n < 0)
	{
		strnum[0] = '-';
		n *= -1;
		i++;
	}
	strnum[digit] = '\0';
	while (digit > i)
	{
		mod = n % 10;
		n /= 10;
		strnum[digit - 1] = mod + '0';
		digit--;
	}
	return (strnum);
}

char	*ft_itoa(int n)
{
	size_t	digit;
	char	*strnum;

	if (n == INT_MIN)
		return (strmin());
	digit = count_digit(n);
	strnum = malloc(sizeof(char) * (digit + 1));
	if (strnum == NULL)
		return (NULL);
	return (ft_itoa_sub(strnum, n, digit));
}
