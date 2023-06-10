/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbardett <mbardett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:22:03 by mbardett          #+#    #+#             */
/*   Updated: 2022/09/08 15:22:33 by mbardett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/lib.h"

char	*ft_revstr(char *s)
{
	int		i;
	char	temp;
	int		c;

	i = ft_strlen(s);
	c = 0;
	while (c < i)
	{
		temp = s[i - 1];
		s[i - 1] = s[c];
		s[c] = temp;
		c++;
		i--;
	}
	return (s);
}

int	get_num(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	else if (n == 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	get_sign(int n, char *s, int *i)
{
	int	c;

	c = 1;
	if (n < 0)
		c = -1;
	if (n == 0)
	{
		s[*i] = '0';
		*i += 1;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		d;
	int		i;
	int		sign;

	d = n;
	i = 0;
	s = (char *)malloc(get_num(n) + 1);
	if (!s)
		return (NULL);
	sign = get_sign(n, s, &i);
	while (n)
	{
		d = n % 10;
		n /= 10;
		s[i] = (d * sign) + '0';
		i++;
	}
	if (sign == -1)
		s[i++] = '-';
	s[i] = 0;
	s = ft_revstr(s);
	return (s);
}
