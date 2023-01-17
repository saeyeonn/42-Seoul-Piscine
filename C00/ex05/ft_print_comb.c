/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:19:12 by saelim            #+#    #+#             */
/*   Updated: 2022/08/24 15:19:16 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar1(char c)
{
	write(1, &c, 1);
}

void	ft_print(int i, int j, int k)
{
	ft_putchar1(i + '0');
	ft_putchar1(j + '0');
	ft_putchar1(k + '0');
	if (i != 7)
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	while (++i <= 7)
	{
		j = i;
		while (++j <= 8)
		{
			k = j;
			while (++k <= 9)
				ft_print(i, j, k);
		}
	}
}
