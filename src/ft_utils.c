/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:06:46 by mbardett          #+#    #+#             */
/*   Updated: 2023/06/16 21:26:11 by mbardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *str, int fd)
{
	size_t	i;

	i = 0;
	while (i <= ft_strlen(str))
		write(fd, &str[i], 1);
	return ;
}

int	check_spaces(const char *s)
{
	int	i;

	i = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = check_spaces(str);
	sign = 1;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-' )
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res * sign);
}

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	a;
	size_t	b;
	char	*new;

	new = (char *)malloc((ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!new)
		return (NULL);
	a = 0;
	b = 0;
	while (str1[a])
	{
		new[b] = str1[a];
		a++;
		b++;
	}
	a = 0;
	while (str2[a])
	{
		new[b] = str2[a];
		b++;
		a++;
	}
	new[b] = 0;
	return (new);
}

//If You are not satisfied with this number of outputs, or if it turns out
//to be too long for norminetter might as well
//consider creating and initializing a char **error_outputs(strings matrix)
//inside an ft_display_error_HELPER, then call it inside this function;
//Yeah, I know, You are welcome;
void	ft_display_error(int error_type)
{
	if (error_type == 0)
		write(2, "Wrong file extension\n", ft_strlen("Wrong file extension\n"));
	if (error_type == 1)
		write(2, "Error:expected only 1 argument\n",
			ft_strlen("Error:expected only 1 argument\n"));
	if (error_type == 2)
		write(2, "Error:Invalid map\n",
			ft_strlen("Error:Invalid map\n"));
	if (error_type == 3)
		write(2, "Error:wrong number of Player, Exit, or Collectibles\n",
			ft_strlen("Error:wrong number of Player, Exit, or Collectibles\n"));
	if (error_type == 666)
		write(1, "Invalid path\n", ft_strlen("Invalid path\n"));
	else
		write(1, "ERROR,initializing self-destruction sequence\n",
			ft_strlen("ERROR,initializing self-destruction sequence\n"));
	exit (1);
}

 int	ft_save(t_game *game)
 {
	int	i, j;
	i = j = 0;
	// FILE 	*file;
	DIR		*dir;
	struct dirent *dent;
	char *name;
	char *tmp;
	int fd;
	int	nbr;
	// char buf[1];
	int curr_max;
	
	curr_max = 0;
	dir = NULL;
	dent = NULL;
	nbr = -1;
	//file = open();
	fd = 0;
	if ((dir = opendir("./saves")) == NULL)
	{
		mkdir("./saves", 0777);
		name = "./saves/000save.ber";
		fd = open(name, O_RDWR | O_CREAT, 777);
		close(fd);
		return 0;
		
	}
	else
	{
		dir = opendir("./saves");
		 while ((dent = readdir(dir)) != NULL)
		{
		 	name = dent->d_name;
		}
		i = 0;
		j = 0;
		while (name[i] >= '0'&& name[i] <= '9')
			i++;
		if (i == 0)
			name = "./saves/000save.ber";
		else
		{
			tmp = malloc(sizeof(char *) * i + 1);
			i = 0;
			while (name[i] >= '0'&& name[i] <= '9')
			{
				tmp[j] = name[i];
				i++;
				j++;
			}
			tmp[j] = '\0';
			name = ft_strjoin("./saves/",ft_itoa(ft_atoi(tmp) + 1));
			name = ft_strjoin(name, "save.ber");
			printf("%s\n", name);
		}
	}
	fd = open(name, O_RDWR | O_CREAT, 777);
	i = 0;
	while ( i < game->dimensions->map_height)
	{
		j = 0;
		while (j < game->dimensions->map_lenght)
		{
			write(fd, &game->dimensions->map_matrix[i][j], 1);
			j++;		
		}
		write(fd, "\n", 1);
		i++;
	}
	close(fd);
	closedir(dir);
	return (0);
 }