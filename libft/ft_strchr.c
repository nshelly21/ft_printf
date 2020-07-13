/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgruyere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:33:37 by dgruyere          #+#    #+#             */
/*   Updated: 2019/09/17 14:59:10 by dgruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*res;

	i = 0;
	res = NULL;
	while (s[i])
	{
		if (s[i] == c)
		{
			res = (char*)&s[i];
			break ;
		}
		i++;
	}
	if (c == 0)
		res = (char*)&s[i];
	return (res);
}
