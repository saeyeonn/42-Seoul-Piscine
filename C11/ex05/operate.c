/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:20:34 by saelim            #+#    #+#             */
/*   Updated: 2022/09/14 14:20:47 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	add(int x, int y)
{
	return (x + y);
}

int	sub(int x, int y)
{
	return (x - y);
}

int	mul(int x, int y)
{
	return (x * y);
}

int	div(int x, int y)
{
	return (x / y);
}

int	mod(int x, int y)
{
	return (x % y);
}
