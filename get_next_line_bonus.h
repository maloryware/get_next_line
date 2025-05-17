/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mal <malory@onenetbeyond.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:53:45 by Mal          #+#    #+#             */
/*   Updated: 2025/05/09 20:29:20 by Mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H

# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1073741823
# endif

/* typedef struct s_filedata
{
	int		fd;
	char	buffer[BUFFER_SIZE + 1];
}	t_filedata; */

/*  */
char	*get_next_line(int fd);
char	*arr_to_line(char *buf, int size);
void	pseudo_memmove(char *buf, int start);
void	flush(char *buf);

#endif