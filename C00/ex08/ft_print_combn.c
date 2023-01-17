/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:19:54 by saelim            #+#    #+#             */
/*   Updated: 2022/09/03 14:45:19 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int index, int value, char *arr, int n)
{
	if (index == n)
	{
		write(1, arr, n);
		if (arr[0] != 10 - n + '0')
			write(1, ", ", 2);
	}
	else
	{
		while (value <= 9)
		{
			arr[index] = value + '0';
			ft_print(index + 1, value + 1, arr, n);
			value++;
		}
	}
}

void	ft_print_combn(int n)
{
	char	arr[10];

	ft_print(0, 0, arr, n);
}
