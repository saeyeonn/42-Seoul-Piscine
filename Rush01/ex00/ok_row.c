/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ok_row.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim2 <hyunskim@student.42seoul.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 08:27:46 by hyunkim2          #+#    #+#             */
/*   Updated: 2022/09/04 17:20:42 by hyunkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ok_row_l(int tab[][10], int obs[][10], int y, int n)
{
	int	c;
	int	i;
	int	max;

	c = 0;
	i = 0;
	max = 0;
	while (i < n)
	{
		if (tab[y][i] > max)
		{
			max = tab[y][i];
			c++;
		}
		i++;
	}
	if (c != obs[2][y])
		return (0);
	return (1);
}

int	ok_row_r(int tab[][10], int obs[][10], int y, int n)
{
	int	c;
	int	i;
	int	max;

	c = 0;
	i = n - 1;
	max = 0;
	while (i >= 0)
	{
		if (tab[y][i] > max)
		{
			max = tab[y][i];
			c++;
		}
		i--;
	}
	if (c != obs[3][y])
		return (0);
	return (1);
}

int	ok_row(int tab[][10], int obs[][10], int y, int n)
{
	if (ok_row_r(tab, obs, y, n) && ok_row_l(tab, obs, y, n))
		return (1);
	return (0);
}
