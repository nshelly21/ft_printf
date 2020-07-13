/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgruyere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:30:43 by dgruyere          #+#    #+#             */
/*   Updated: 2019/09/26 10:51:15 by dgruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;

	if (!s1 || !s2 || !(res = (char*)malloc(sizeof(char) *
				(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	ft_strcpy(res, (char*)s1);
	ft_strcpy(res + ft_strlen(s1), (char*)s2);
	return (res);
}
