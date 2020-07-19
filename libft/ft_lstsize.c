/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgruyere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 18:48:33 by dgruyere          #+#    #+#             */
/*   Updated: 2020/07/18 22:40:37 by dgruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list **head)
{
	t_list		*lst;
	int			i;

	i = 0;
	lst = *head;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
