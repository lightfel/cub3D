/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhikaru <nhikaru@student.42tokyo.j>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 01:12:01 by nhikaru           #+#    #+#             */
/*   Updated: 2020/10/19 23:57:16 by nhikaru          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lstlast;

	lstlast = ft_lstlast(*lst);
	new->next = NULL;
	if (lstlast == NULL)
	{
		*lst = new;
		return ;
	}
	lstlast->next = new;
}
