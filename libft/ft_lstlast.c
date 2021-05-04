/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 01:04:05 by nhikaru           #+#    #+#             */
/*   Updated: 2020/10/19 23:57:40 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;
	t_list	*lstlast;

	if (lst == NULL)
		return (NULL);
	current = lst;
	while (current != NULL)
	{
		lstlast = current;
		current = current->next;
	}
	return (lstlast);
}
