/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davpache <davpache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:26:40 by davpache          #+#    #+#             */
/*   Updated: 2025/05/09 18:41:27 by davpache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*arr_to_line(char *buf, int size)
{
	char	*out;
	int		i;
	int		sref;

	i = 0;
	sref = size;
	out = malloc(sref + 1);
	flush(out);
	while (sref >= 0)
	{
		out[sref] = buf[sref];
		sref--;
	}
	return (out);
}

void	pseudo_memmove(char *buf, int start)
{
	int	i;

	start++;
	i = 0;
	while (buf[i + start - 1])
	{
		buf[i] = buf[i + start];
		i++;
	}
}

void	flush(char *buf)
{
	int	i;

	i = -1;
	while (buf[++i])
		buf[i] = 0;
}
