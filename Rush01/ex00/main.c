/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunkim2 <hyunskim@student.42seoul.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 07:55:16 by hyunkim2          #+#    #+#             */
/*   Updated: 2022/09/04 18:13:14 by hyunkim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		cut(int tab[][10], int obs[][10], int k, int n);
void	ft_putstr(char *str);

int	is_n(char *str)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= '9')
			c++;
		i++;
	}
	return (c / 4);
}

int	is_ok(char *str, int n)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (str[i])
	{
		while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
			i++;
		if (str[i] && (str[i] < '1' || str[i] > n + '0'))
			return (0);
		if (str[i] >= '1' && str[i] <= n + '0')
		{
				i++;
				c++;
		}
		else
			i++;
		while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
			i++;
	}
	if (c != 16 && c != 20 && c != 24 && c != 28)
		return (0);
	return (1);
}

void	asign(int obs[][10], char *str, int n)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (str[i])
	{
		if (str[i] >= '1' && str[i] <= n + '0')
		{
			obs[y][x] = str[i] - '0';
			x++;
		}
		if (x == n)
		{
			y++;
			x = 0;
		}
		i++;
	}
}

void	initialization(int arr[][10])
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			arr[i][j] = 0;
			j++;
		}
	i++;
	}
}

int	main(int ac, char **av)
{
	int	tab[10][10];
	int	obs[10][10];

	if (ac != 2)
	{
		ft_putstr("Error\n");
		return (0);
	}
	initialization(tab);
	initialization(obs);
	if (is_ok(av[1], is_n(av[1])))
	{
		asign(obs, av[1], is_n(av[1]));
		if (cut(tab, obs, 0, is_n(av[1])) == 0)
		{
			ft_putstr("Error\n");
			return (0);
		}
	}
	else
	{
		ft_putstr("Error\n");
		return (0);
	}
}
