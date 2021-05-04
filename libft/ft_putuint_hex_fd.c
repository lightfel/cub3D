/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_hex_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 20:48:02 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/04 05:36:09 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_putlen(unsigned int num)
{
	int	i;

	i = 1;
	if (num != 0)
	{
		num /= 16;
		while (num != 0)
		{
			num /= 16;
			i++;
		}
	}
	return (i);
}

ssize_t	ft_putuint_hex_fd(unsigned int n, int fd, bool isupper)
{
	if (n < 16)
	{
		if (isupper == true)
			ft_putchar_fd("0123456789ABCDEF"[n], fd);
		else
			ft_putchar_fd("0123456789abcdef"[n], fd);
	}
	else
	{
		ft_putuint_hex_fd(n / 16, fd, isupper);
		ft_putuint_hex_fd(n % 16, fd, isupper);
	}
	return (count_putlen(n));
}
