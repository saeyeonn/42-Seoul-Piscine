/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 21:16:44 by saelim            #+#    #+#             */
/*   Updated: 2022/09/13 18:59:28 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int			i;
	long long	result;
	int			*tmp;

	i = 0;
	if (range == NULL)
		return (-1);
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	result = (long long) max - (long long) min;
	tmp = (int *)malloc(sizeof(int) * (max - min));
	if (!tmp)
		return (-1);
	while (i < result)
		tmp[i++] = min++;
	*range = tmp;
	return ((int) result);
}
