/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:43:02 by mbardett          #+#    #+#             */
/*   Updated: 2022/09/17 14:57:00 by mbardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

//currently not using any of this functions
char	*ft_strchr(char *s, int c)
{
	while (*s != '\0')
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

// int	**enemy_new_coords(t_game *game)
// {
// 	int	x;
// 	int	y;
// 	int	**enc;
// 	int	b;

// 	b = 0;
// 	y = 0;
// 	enc = (int **)malloc(sizeof(int) * (game->enemy_number));
// 	if (!enc)
// 		return (NULL);
// 	while (y < game->dimensions.map_height)
// 	{
// 		x = 0;
// 		while (x < game->dimensions.map_lenght)
// 		{
// 			if (game->dimensions.map_matrix[y][x] == 'M')
// 			{
// 				enc[0][b] = x;
// 				enc[1][b] = y;
// 				b++;
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (enc);
// }
