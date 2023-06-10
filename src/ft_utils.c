/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 17:06:46 by mbardett          #+#    #+#             */
/*   Updated: 2022/11/03 16:27:49 by mbardett         ###   ########.fr       */
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
