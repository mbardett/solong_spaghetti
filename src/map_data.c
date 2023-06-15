/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 12:29:51 by mbardett          #+#    #+#             */
/*   Updated: 2023/06/15 12:59:07 by mbardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

int	get_length_helper(int fd, int length_check)
{
	int		i;
	char	*str;

	str = gnl_so_long(fd);
	while (str != NULL)
	{
		i = 0;
		while (str[i] != '\n' && str[i] != '\0')
			i++;
		if (i != length_check)
			ft_display_error(2);
		free(str);
		str = gnl_so_long(fd);
	}
	free(str);
	close(fd);
	return (i);
}

//check and get map length
int	get_length(char *file_name)
{
	int		fd;
	int		i;
	int		x;
	char	*str;

	fd = open(file_name, O_RDONLY, 0);
	str = gnl_so_long(fd);
	i = 0;
	while (str[i] != '\n')
		i++;
	free(str);
	x = i;
	i = get_length_helper(fd, i);
	return (i);
}

int	get_height(char *file_name)
{
	int		fd;
	int		height;
	char	*str;

	fd = open(file_name, O_RDONLY, 0);
	height = 0;
	str = gnl_so_long(fd);
	while (str != NULL)
	{
		height++;
		free(str);
		str = gnl_so_long(fd);
	}
	free(str);
	close(fd);
	return (height);
}

void	fill_matrix(char *to_fill, char *lines)
{
	int	i;

	i = 0;
	while (lines[i] != '\n' && lines[i] != '\0')
	{
		to_fill[i] = lines[i];
		i++;
	}
	to_fill[i] = '\0';
}

void	read_file(char *nome_file, t_coordinate *data)
{
	int		fd;
	int		i;

	fd = open(nome_file, O_RDONLY, 0);
	data->map_lenght = get_length(nome_file);
	data->map_height = get_height(nome_file);
	data->map_matrix = (char **)malloc(sizeof(char *) * (data->map_height + 1));
	if (!data->map_matrix)
		exit (0);
	i = -1;
	fd = open(nome_file, O_RDONLY, 0);
	i = -1;
	while (i < data->map_height)
		data->map_matrix[++i] = gnl_so_long(fd);
	close (fd);
}

void	new_readfile(char *nome_file, t_coordinate *data)
{
	int	fd = open(nome_file, O_RDONLY, 0);
	int	i = 0;
	int	j = 0;
	//char *le_gnl;
	char *join;

	data->map_lenght = get_length(nome_file) + 2;
	data->map_height = get_height(nome_file) + 6;
	data->map_matrix = (char **)malloc(sizeof(char *) * data->map_height + 1);
	while (i < data->map_height + 1)
	{
		data->map_matrix[i] = malloc(sizeof(char ) * data->map_lenght + 1);
		// data->map_matrix[i][0] = 'l';
		// data->map_matrix[i][data->map_lenght] = 'r';
		// data->map_matrix[i][data->map_lenght + 1] = '\n';
		i++;
	}
	memset(data->map_matrix[0], 'u', data->map_lenght);
	memset(data->map_matrix[data->map_height - 5], 'b', data->map_lenght);
	memset(data->map_matrix[data->map_height -4], 'u', data->map_lenght );
	memset(data->map_matrix[data->map_height -1], 'b', data->map_lenght );
	i = 1;
	while (i < data->map_height + 1)
	{
		j = 0;
		data->map_matrix[i][0] = 'l';
		if (i > data->map_height - 4 && i < data->map_height)
		{	
			while(j < data->map_lenght)
			{
				if ((j == 1 || j == 2) && i != data->map_height -1)
					data->map_matrix[i][j] = 'i';
				else if (j == data->map_lenght -2 && i == data->map_height -3)
					data->map_matrix[i][j] = 'S';
				else if (j == data->map_lenght -2 && i == data->map_height -2)
					data->map_matrix[i][j] = 'L';
				else if (j == data->map_lenght -3 && i == data->map_height -3)
					data->map_matrix[i][j] = 'R';
				else if (j == data->map_lenght -3 && i == data->map_height -2)
					data->map_matrix[i][j] = 'O';
				else if (data->map_matrix[i][j] != 'i' && data->map_matrix[i][j] != 'S' && data->map_matrix[i][j] != 'L' && data->map_matrix[i][j] != 'R' && data->map_matrix[i][j] != 'O' && data->map_matrix[i][j] != 'b' && data->map_matrix[i][j] != 'l')
					data->map_matrix[i][j] = 'w';	
				j++;
			}
		}		
		data->map_matrix[i][data->map_lenght -1] = 'r';
		// data->map_matrix[i][data->map_lenght] = '\0';
		i++;
	}
	data->map_matrix[0][0] = 'x';
	data->map_matrix[0][data->map_lenght -1] = 'x';
	data->map_matrix[data->map_height - 5][0] =  'x';
	data->map_matrix[data->map_height - 5][data->map_lenght -1] =  'x';
	data->map_matrix[data->map_height - 4][0] =  'x';
	data->map_matrix[data->map_height - 4][data->map_lenght -1] =  'x';
	data->map_matrix[data->map_height -1][0] =  'x';
	data->map_matrix[data->map_height -1][data->map_lenght -1] =  'x';
	
	//fin qui gestiti bordi e angoli GUI, mancano copia .ber, inventario, icone, text window
	i = 1;
	j = 1;
	write(1, "CULO2\n", 6);
	// join = gnl_so_long(fd);
	// printf("")
	while (i < data->map_height - 5)
	{
		join = gnl_so_long(fd);
		// printf("%s\n", join);
		j = 1;
		while (j < data->map_lenght -1)
		{
			data->map_matrix[i][j] = join[j -1];
			//write(1, "joined\n", 7);
			j++;
		}
		// free(join);
		i++;
	}
	i = 1;
	j = 1;
	while (i < data->map_height -6)
	{
		j = 1;
		while (j < data->map_lenght +1)
		{
			if (  i == 1 && data->map_matrix[i][j] == '1' && j %5 == 0 && 1 < j && j < data->map_lenght - 2)
				data->map_matrix[i][j] = 'f';
			else if (j > 1 && 1 < i && i< (data->map_height - 7) && data->map_matrix[i][j] == '1' && data->map_matrix[i + 1][j] != '1' && data->map_matrix[i + 1][j + 1] != '1' && data->map_matrix[i + 1][j - 1] != '1')
					data->map_matrix[i][j] = 'f';
			j++;
		}
		i++;
		
	}
	write(1, "CULO1\n", 6);
	free(join);
	close(fd);
	i =0;
	j =0;
	while (i < data->map_height)
	{
		printf("%s\n", data->map_matrix[i]);
		i++;
	}
}