/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 20:23:40 by saelim            #+#    #+#             */
/*   Updated: 2022/09/12 14:55:06 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	*t_ptr;

	if (min >= max)
		return (NULL);
	tab = (int *) malloc (sizeof(int) * (max - min));
	t_ptr = tab;
	if (!tab)
		return (NULL);
	while (min < max)
	{
		*tab = min;
		tab++;
		min++;
	}
	return (t_ptr);
}
