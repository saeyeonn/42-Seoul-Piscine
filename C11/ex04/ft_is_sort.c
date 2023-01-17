/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 23:04:41 by saelim            #+#    #+#             */
/*   Updated: 2022/09/13 23:06:31 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_same(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 2 && f(tab[i], tab[i + 1]) == 0)
		i++;
	return (i);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	if (tab == 0)
		return (1);
	i = ft_check_same(tab, length, f);
	if (f(tab[i], tab[i + 1]) >= 0)
	{
		while (i < length - 1)
		{
			if (f(tab[i], tab[i + 1]) < 0)
				return (0);
			i++;
		}
	}
	else
	{
		while (i < length - 1)
		{
			if (f(tab[i], tab[i + 1]) > 0)
				return (0);
			i++;
		}
	}
	return (1);
}
