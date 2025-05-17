/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:56:28 by Mal          #+#    #+#             */
/*   Updated: 2025/05/09 20:37:40 by Mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/* #include "get_next_line_utils.c" */

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*out;
	int			i;

	if (fd < 0)
		return (NULL);
	i = 0;
	if (!*buf)
		if (read(fd, buf, BUFFER_SIZE) <= 0)
			return (NULL);
	while (buf[i] != '\n' && buf[i])
		i++;
	out = arr_to_line(buf, i);
	if (buf[i] == '\n')
		pseudo_memmove(buf, i);
	else
		flush(buf);
	return (out);
}

/* int main()
{
	int		tmp;
	int		i;
	char	*s;

	tmp = open("test1.txt", O_RDONLY);
	i = 0;
	s = malloc(1);
	while (s)
	{
		if (i)
			printf("%s", s);
		free(s);
		s = get_next_line(tmp);
		if (s)
			i++;
	}
	free(s);
} */
