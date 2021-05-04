/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 01:39:15 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/04 05:31:55 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*intmax_to_str(void)
{
	static char	intmax[11];

	intmax[0] = '2';
	intmax[1] = '1';
	intmax[2] = '4';
	intmax[3] = '7';
	intmax[4] = '4';
	intmax[5] = '8';
	intmax[6] = '3';
	intmax[7] = '6';
	intmax[8] = '4';
	intmax[9] = '7';
	intmax[10] = '\0';
	return (intmax);
}

static bool	isoverflow(char *num, int sign)
{
	char	*intmax;
	int		numlen;

	if (num[10] != '\0')
	{
		return (true);
	}
	else if (num[9] != '\0')
	{
		intmax = intmax_to_str();
		numlen = ft_strlen(num);
		if (sign == -1)
		{
			intmax[9] = '8';
		}
		if (ft_strncmp(num, intmax, numlen) > 0)
		{
			return (true);
		}
	}
	return (false);
}

int	num_to_int(char *num, int sign)
{
	int		i;
	int		rsl;
	char	*intmax;

	intmax = intmax_to_str();
	intmax[9] = '8';
	if (ft_strncmp(num, intmax, 11) == 0)
		return (INT_MIN);
	i = 0;
	rsl = 0;
	while (num[i] != '\0')
	{
		rsl = rsl * 10 + (num[i] - '0');
		i++;
	}
	return (rsl * sign);
}

static int	ft_atoi_sub(const char *str, int sign)
{
	char	num[12];
	int		i;

	num[9] = '\0';
	num[10] = '\0';
	i = 0;
	while (str[i] >= '0' && str[i] <= '9' && i < 11)
	{
		num[i] = str[i];
		i++;
	}
	num[i] = '\0';
	if (i == 0)
		return (0);
	else if (isoverflow(num, sign))
	{
		if (sign == 1)
			return (-1);
		else
			return (0);
	}
	return (num_to_int(num, sign));
}

int	ft_atoi(const char *str)
{
	int		sign;

	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	sign = 1;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str == '0')
		str++;
	return (ft_atoi_sub(str, sign));
}
