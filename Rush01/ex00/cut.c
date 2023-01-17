/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim2 <hyunskim@student.42seoul.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 08:55:02 by hyunkim2          #+#    #+#             */
/*   Updated: 2022/09/04 18:00:53 by hyunkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_puttab(int tab[][10], int *total, int n);
int		ok_col(int tab[][10], int obs[][10], int x, int n);
int		ok_row(int tab[][10], int obs[][10], int y, int n);
int		ok_dup(int tab[][10], int x, int y);

int	cut(int tab[][10], int obs[][10], int k, int n)
{
	int	total;

	total = 0;
	tab[k / n][k % n] = 1;
	while (tab[k / n][k % n] <= n && total == 0)
	{
		if (ok_dup(tab, k % n, k / n) && k % n <= n - 1)
		{
			if (k % n == n - 1 && k / n < n - 1 && ok_row(tab, obs, k / n, n))
				total = cut(tab, obs, k + 1, n);
			if (k / n == n - 1 && k % n < n - 1 && ok_col(tab, obs, k % n, n))
				total = cut(tab, obs, k + 1, n);
			if (k / n < n - 1 && k % n < n - 1)
				total = cut(tab, obs, k + 1, n);
			if ((k / n == n - 1 && k % n == n - 1) \
					&& ok_row(tab, obs, k / n, n) && ok_col(tab, obs, k % n, n))
				ft_puttab(tab, &total, n);
		}
		tab[k / n][k % n]++;
	}
	if (total != 0)
		return (total);
	return (0);
}
