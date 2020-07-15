/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgruyere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 16:21:04 by dgruyere          #+#    #+#             */
/*   Updated: 2019/09/19 19:56:26 by dgruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*res;
	int		i;

	i = 0;
	res = NULL;
	if (!s || !(res = (char*)ft_memalloc(len + 1)))
		return (NULL);
	while ((int)len > 0)
	{
		res[i] = s[start];
		start++;
		len--;
		i++;
	}
	res[i] = '\0';
	return (res);
}
