/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:18:39 by saelim            #+#    #+#             */
/*   Updated: 2022/08/29 16:23:53 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char	*str)
{
	unsigned char	*u_str;

	u_str = (unsigned char *) str;
	while (*u_str)
	{
		if (*u_str < 32 || *u_str > 126)
		{
			write(1, "\\", 1);
			ft_putchar("0123456789abcdef"[*u_str / 16]);
			ft_putchar("0123456789abcdef"[*u_str % 16]);
		}
		else
			write(1, u_str, 1);
		u_str++;
	}
}
