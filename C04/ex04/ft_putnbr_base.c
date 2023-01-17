/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:30:58 by saelim            #+#    #+#             */
/*   Updated: 2022/09/03 21:42:43 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

long long	ft_checkingbase(char *base)
{
	char	*b_ptr;
	int		len;

	len = 0;
	while (*base)
	{
		b_ptr = base + 1;
		if (*base == '-' || *base == '+')
			return (-1);
		while (*b_ptr)
		{
			if (*base == *b_ptr)
				return (-1);
			b_ptr++;
		}
		base++;
		len++;
	}
	return (len);
}

void	ft_printf(long long l_nbr, char *base, long long b_len)
{
	if (l_nbr < 0)
	{
		write(1, "-", 1);
		l_nbr *= -1;
	}
	if (l_nbr >= b_len)
		ft_printf(l_nbr / b_len, base, b_len);
	ft_putchar(base[l_nbr % b_len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long long	b_len;
	long long	l_nbr;

	l_nbr = (long long) nbr;
	b_len = ft_checkingbase(base);
	if (b_len <= 1)
		return ;
	ft_printf(l_nbr, base, b_len);
}
