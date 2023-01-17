/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 21:35:48 by saelim            #+#    #+#             */
/*   Updated: 2022/09/07 22:02:28 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char	*s1, char	*s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_swap(char	**a, char	**b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_int_tab(char **tab, int size)
{
	int	i;
	int	count;

	count = 0;
	while (++count < size)
	{
		i = 0;
		while (++i < size - 1)
			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
				ft_swap(&tab[i], &tab[i + 1]);
	}
}

int	main(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	if (argc > 1)
		ft_sort_int_tab(argv, argc);
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
			write(1, &argv[i][j], 1);
		write(1, "\n", 1);
	}
	return (0);
}
