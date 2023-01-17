/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 15:51:47 by saelim            #+#    #+#             */
/*   Updated: 2022/08/27 15:56:07 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char a);

void	topdown_line(char L_point, char R_point, char Middle, int x)
{
	int	curloc_x;

	curloc_x = 0;
	while (++curloc_x <= x)
	{
		if (curloc_x == 1)
			ft_putchar(L_point);
		else if (curloc_x == x)
			ft_putchar(R_point);
		else
			ft_putchar(Middle);
	}
	ft_putchar('\n');
}

void	middle_line(char LR_point, char Middle, int x)
{
	int	curloc_x;

	curloc_x = 0;
	while (++curloc_x <= x)
	{
		if (curloc_x == 1 || curloc_x == x)
			ft_putchar(LR_point);
		else
			ft_putchar(Middle);
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	curloc_y;

	curloc_y = 0;
	while (++curloc_y <= y)
	{
		if (curloc_y == 1)
			topdown_line('o', 'o', '-', x);
		else if (curloc_y == y)
			topdown_line('o', 'o', '-', x);
		else
			middle_line('|', ' ', x);
	}
}
