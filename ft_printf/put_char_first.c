/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_char_first.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgruyere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 19:25:07 by dgruyere          #+#    #+#             */
/*   Updated: 2020/07/18 03:09:59 by dgruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*pcf_skip_sp(char *str, char c)
{
	char	*tmp;
	int		i;

	tmp = NULL;
	i = -1;
	if (!(tmp = (char*)malloc(sizeof(char) * ft_strlen(str) + 2)))
		return (NULL);
	while (str[++i] == ' ')
		tmp[i] = ' ';
	tmp[i - 1] = c;
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*put_char_first(char *str, char c)
{
	char	*tmp;
	char	*tmp1;
	int		i;

	tmp = NULL;
	i = -1;
	if (!(tmp = (char*)malloc(sizeof(char) * ft_strlen(str) + 2)))
		return (NULL);
	tmp[0] = c;
	while (str[++i])
		tmp[i + 1] = str[i];
	tmp[i + 1] = '\0';
	tmp1 = tmp;
	free(tmp1);
	return (tmp);
}
