/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 15:16:00 by mbardett          #+#    #+#             */
/*   Updated: 2022/09/20 14:32:17 by mbardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

int	check_conditions(char	*str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*read_save_line(char *str)
{
	int		i;
	char	*newbuffer;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[0] == '\0')
		return (NULL);
	newbuffer = malloc(sizeof(char) * i + 2);
	if (!newbuffer)
		return (NULL);
	i = 0;
	while (str[i] != '\n' && str[i])
	{
		newbuffer[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		newbuffer[i++] = '\n';
	newbuffer[i] = '\0';
	return (newbuffer);
}

char	*next_loop(char *str)
{
	int		i;
	int		j;
	char	*newbuffer;

	i = 0;
	j = ft_strlen(str);
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\0')
	{
		free (str);
		return (NULL);
	}
	newbuffer = malloc(sizeof(char) * (j - i));
	if (!newbuffer)
		return (NULL);
	j = 0;
	i++;
	while (str[i])
		newbuffer[j++] = str[i++];
	newbuffer[j] = '\0';
	free(str);
	return (newbuffer);
}

char	*already_read(int fd, char *buffer, char *temp, char *str)
{
	int	result;

	result = 1;
	while (result != 0)
	{
		result = read(fd, buffer, 1);
		if (result == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[result] = '\0';
		temp = str;
		if (temp == NULL)
		{
			temp = malloc(sizeof(char) * 1);
			temp[0] = '\0';
		}
		str = ft_strjoin(temp, buffer);
		free(temp);
		if (check_conditions(str) == 1)
			break ;
	}
	free(buffer);
	return (str);
}

char	*get_next_line(int fd, char **line)
{
	static char	*str;
	char		*buffer;
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
	*line = read_save_line(str);
	str = next_loop(str);
	return (*line);
}
