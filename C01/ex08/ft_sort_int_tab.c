/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:21:34 by saelim            #+#    #+#             */
/*   Updated: 2022/08/29 16:40:08 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void	ft_swap2(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;

	while (size-- > 0)
	{
		i = -1;
		while (++i < size)
			if (tab[i] > tab[i + 1])
				ft_swap2(&tab[i], &tab[i + 1]);
	}
}
