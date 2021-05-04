/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 00:51:35 by nhikaru           #+#    #+#             */
/*   Updated: 2020/10/19 23:58:00 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*current;

	if (lst == NULL)
		return (0);
	current = lst->next;
	i = 1;
	while (current != NULL)
	{
		current = current->next;
		i++;
	}
	return (i);
}
