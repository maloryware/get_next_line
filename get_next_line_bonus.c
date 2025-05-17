/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:56:28 by Mal          #+#    #+#             */
/*   Updated: 2025/05/09 20:28:11 by Mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
/* #include "get_next_line_utils_bonus.c" */

char	*get_next_line(int fd)
{
	static char	buf[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*out;
	int			i;

	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	i = 0;
	if (!*buf[fd])
		if (read(fd, buf[fd], BUFFER_SIZE) <= 0)
			return (NULL);
	while (buf[fd][i] != '\n' && buf[fd][i])
		i++;
	out = arr_to_line(buf[fd], i);
	if (buf[fd][i] == '\n')
		pseudo_memmove(buf[fd], i);
	else
		flush(buf[fd]);
	return (out);
}

/* int main()
{
	int		tmp;
	int		tmp2;
	char	*s;
	char	*ss;

	tmp = open("test1.txt", O_RDONLY);
	tmp2 = open("test2.txt", O_RDONLY);
	while ((s = get_next_line(tmp)) && (ss = get_next_line(tmp2)))
	{
		printf("%s", s);
		printf("%s", ss);
	}
} */
