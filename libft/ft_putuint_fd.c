/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 20:41:18 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/04 05:29:41 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit(unsigned int num)
{
	int	i;

	i = 1;
	if (num != 0)
	{
		num /= 10;
		while (num != 0)
		{
			num /= 10;
			i++;
		}
	}
	return (i);
}

ssize_t	ft_putuint_fd(unsigned int n, int fd)
{
	if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else
	{
		ft_putuint_fd(n / 10, fd);
		ft_putuint_fd(n % 10, fd);
	}
	return (count_digit(n));
}
