/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ok_col.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim2 <hyunskim@student.42seoul.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 08:39:34 by hyunkim2          #+#    #+#             */
/*   Updated: 2022/09/04 17:18:57 by hyunkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ok_col_u(int tab[][10], int obs[][10], int x, int n)
{
	int	c;
	int	i;
	int	max;

	c = 0;
	i = 0;
	max = 0;
	while (i < n)
	{
		if (tab[i][x] > max)
		{
			max = tab[i][x];
			c++;
		}
		i++;
	}
	if (c != obs[0][x])
		return (0);
	return (1);
}

int	ok_col_d(int tab[][10], int obs[][10], int x, int n)
{
	int	c;
	int	i;
	int	max;

	c = 0;
	i = n - 1;
	max = 0;
	while (i >= 0)
	{
		if (tab[i][x] > max)
		{
			max = tab[i][x];
			c++;
		}
		i--;
	}
	if (c != obs[1][x])
		return (0);
	return (1);
}

int	ok_col(int tab[][10], int obs[][10], int x, int n)
{
	if (ok_col_u(tab, obs, x, n) && ok_col_d(tab, obs, x, n))
		return (1);
	return (0);
}
