/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgruyere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:25:07 by dgruyere          #+#    #+#             */
/*   Updated: 2020/07/17 19:25:09 by dgruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*put_char_first(char *str, char c)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	i = -1;
	if (!(tmp = (char*)malloc(sizeof(char) * ft_strlen(str) + 2)))
		return (NULL);
	tmp[0] = c;
	while (str[++i])
		tmp[i + 1] = str[i];
	tmp[i + 1] = '\0';
	free(str);
	return (tmp);
}
