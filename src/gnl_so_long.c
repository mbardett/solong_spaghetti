/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_so_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:12:44 by mbardett          #+#    #+#             */
/*   Updated: 2022/09/09 14:14:28 by mbardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

//basic gnl from 42 assignment takes as arguments both a fildes and a char **;
//in this version here we just want it to take only one fildes as argument;
char	*gnl_so_long(int fd)
{
	static char	*str;
	char		*buffer;
	char		*line;
	char		*temp;

	buffer = NULL;
	temp = NULL;
	if (fd < 0 || read(fd, buffer, 0) < 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	str = already_read(fd, buffer, temp, str);
	if (str == NULL)
		return (NULL);
	line = read_save_line(str);
	str = next_loop(str);
	return (line);
}
