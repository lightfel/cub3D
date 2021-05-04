/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 20:48:02 by nhikaru           #+#    #+#             */
/*   Updated: 2021/05/04 05:35:05 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digit_pointer(uintptr_t num)
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
	return (i + 2);
}

ssize_t	ft_putpointer_fd(uintptr_t n, int fd, bool flag)
{
	ssize_t	putlen;

	putlen = count_digit_pointer(n);
	if (flag == true)
		ft_putstr_fd("0x", 1);
	if (n < 16)
		ft_putchar_fd("0123456789abcdef"[n], fd);
	else
	{
		ft_putpointer_fd(n / 16, fd, false);
		ft_putpointer_fd(n % 16, fd, false);
	}
	return (putlen);
}
