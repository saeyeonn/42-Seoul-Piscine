/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim2 <hyunskim@student.42seoul.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 08:22:21 by hyunkim2          #+#    #+#             */
/*   Updated: 2022/09/04 17:12:16 by hyunkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_puttab(int tab[][10], int *total, int n)
{
	int	x;
	int	y;

	y = 0;
	while (y < n)
	{
		x = 0;
		while (x < n)
		{
			ft_putchar(tab[y][x] + '0');
			x++;
			if (x < n)
				ft_putchar(' ');
		}
		ft_putchar('\n');
		y++;
	}
	(*total)++;
}
