/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_management.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:53:36 by mbardett          #+#    #+#             */
/*   Updated: 2022/09/17 13:26:39 by mbardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

// this might be useful later,
//in case we want to add more elements(such as enemies,collectibles etc etc)
//or we want tobe able to load new sprites and so on
//
// t_enemy	*ft_lstnew(int	x, int y)
// {
// 	t_enemy	*link;

// 	link = (t_enemy *)malloc(sizeof(t_enemy));
// 	if (link == NULL)
// 		return (NULL);
// 	link->x = x;
// 	link->y = y;
// 	link->next_enemy = NULL;
// 	return (link);
// }

// t_enemy	*ft_lstlast(t_enemy *lst)
// {
// 	if (lst)
// 	{
// 		while (lst->next_enemy)
// 			lst = lst->next_enemy;
// 	}
// 	return (lst);
// }

// void	ft_lstadd_back(t_enemy *lst, t_enemy *new)
// {
// 	t_enemy	*last_element;

// 	last_element = ft_lstlast(lst);
// 	if (!last_element)
// 		lst = new;
// 	else
// 		last_element->next_enemy = new;
// }
