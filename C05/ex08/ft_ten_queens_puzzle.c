/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 21:08:53 by saelim            #+#    #+#             */
/*   Updated: 2022/09/11 16:42:48 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_check(int x, int board[])
{
	int		i;
	int		tmp;

	i = 0;
	while (i < x)
	{
		tmp = board[x] - board[i];
		if (tmp < 0)
			tmp *= -1;
		if (board[x] == board[i] || x - i == tmp)
			return (0);
		i++;
	}
	return (1);
}

void	ft_print_board(int board[])
{
	int		i;
	char	tmp;

	i = 0;
	while (i < 10)
	{
		tmp = board[i] + 48;
		write(1, &tmp, 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_dfs(int x, int *cnt, int board[])
{
	int		i;

	i = 0;
	if (x == 10)
	{
		*cnt = *cnt + 1;
		ft_print_board(board);
		return ;
	}
	while (i < 10)
	{
		board[x] = i;
		if (ft_check(x, board))
			ft_dfs(x + 1, cnt, board);
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int		cnt;
	int		i;
	int		board[10];

	cnt = 0;
	i = 0;
	while (i < 10)
	{
		board[i] = 0;
		i++;
	}
	ft_dfs(0, &cnt, board);
	return (cnt);
}
