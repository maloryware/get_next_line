/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 21:34:32 by Mal               #+#    #+#             */
/*   Updated: 2025/05/21 15:48:29 by Mal              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int b)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (b == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i])
	{
		if (s[i] == (char)b)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

char	*full_line(char *out, char *arr)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = -1;
	while (arr[i] != '\0' && arr[i] != '\n')
		i++;
	if (arr[i] == '\n')
		i++;
	temp = malloc(i + 1);
	if (!temp)
		return (NULL);
	while (++j < i)
		temp[j] = arr[j];
	temp[j] = '\0';
	j = 0;
	while (arr[i] != '\0')
		arr[j++] = arr[i++];
	arr[j] = '\0';
	out = ft_strjoin(out, temp);
	free(temp);
	return (out);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*joined;

	j = 0;
	i = 0;
	joined = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!joined)
		return (NULL);
	if (s1)
	{
		while (s1[i] != '\0')
		{
			joined[i] = s1[i];
			i++;
		}
	}
	while (s2[j] != '\0')
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	free(s1);
	return (joined);
}
