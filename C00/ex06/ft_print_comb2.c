/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:19:26 by saelim            #+#    #+#             */
/*   Updated: 2022/08/24 15:19:30 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar2(char c)
{
	write(1, &c, 1);
}

void	ft_print2(int a, int b)
{
	ft_putchar2(a / 10 + '0');
	ft_putchar2(a % 10 + '0');
	write(1, " ", 1);
	ft_putchar2(b / 10 + '0');
	ft_putchar2(b % 10 + '0');
	if (a != 98)
		write(1, ", ", 2);
}	

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = -1;
	while (++a <= 98)
	{
		b = a;
		while (++b <= 99)
			ft_print2(a, b);
	}
}
