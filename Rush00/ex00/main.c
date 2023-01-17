/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:51:19 by saelim            #+#    #+#             */
/*   Updated: 2022/08/28 18:39:57 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);

int	ft_atoi(char	*str)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		num = num * 10 + (*str - '0');
		str++;
	}
	return (num * sign);
}

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[2]);
	if (argc == 3 && x > 0 && y > 0)
		rush(x, y);
	else
		write(1, "WRONG INPUT", 11);
	return (0);
}
