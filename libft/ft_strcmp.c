/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgruyere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 19:23:48 by dgruyere          #+#    #+#             */
/*   Updated: 2019/09/17 15:47:04 by dgruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	if (s1[0] == '\0' && s2[0] == '\0')
		return (0);
	return (ft_memcmp(s1, s2, ft_strlen(s1) < ft_strlen(s2) ? ft_strlen(s2) :
			ft_strlen(s1)));
}
