/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:20:01 by saelim            #+#    #+#             */
/*   Updated: 2022/09/14 14:20:16 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "do_op.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	func(int x, char *c, int y)
{
	int	i;
	int	(*f[5])(int, int);

	f[0] = &add;
	f[1] = &sub;
	f[2] = &mul;
	f[3] = &div;
	f[4] = &mod;
	i = 1;
	if (c[0] == '+')
		i = f[0](x, y);
	else if (c[0] == '-')
		i = f[1](x, y);
	else if (c[0] == '*')
		i = f[2](x, y);
	else if (c[0] == '/')
		i = f[3](x, y);
	else if (c[0] == '%')
		i = f[4](x, y);
	return (i);
}

int	is_operator(char *op)
{
	if (ft_strlen(op) != 1)
		return (0);
	if (!(*op == '+' || *op == '-' || *op == '*' || *op == '/' || *op == '%'))
		return (0);
	return (1);
}

void	ft_do_op(char *x, char *c, char *y)
{
	int	left;
	int	right;

	left = ft_atoi(x);
	right = ft_atoi(y);
	if (!(is_operator(c)))
		ft_putstr("0\n");
	else if (c[0] == '/' && right == 0)
		ft_putstr("Stop : division by zero\n");
	else if (c[0] == '%' && right == 0)
		ft_putstr("Stop : modulo by zero\n");
	else
	{
		ft_putnbr(func(left, c, right));
		ft_putstr("\n");
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 4)
		ft_do_op(argv[1], argv[2], argv[3]);
	return (0);
}
