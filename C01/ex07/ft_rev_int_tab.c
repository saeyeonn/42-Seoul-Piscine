/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 15:21:29 by saelim            #+#    #+#             */
/*   Updated: 2022/08/29 16:30:52 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap1(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;

	i = -1;
	while (++i < size / 2)
		ft_swap1(&tab[i], &tab[size - 1 - i]);
}
