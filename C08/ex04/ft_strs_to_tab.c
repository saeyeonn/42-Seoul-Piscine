/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 21:13:47 by saelim            #+#    #+#             */
/*   Updated: 2022/09/08 18:53:56 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (str[++i])
		++len;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	char	*d_ptr;

	dup = (char *) malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dup)
		return (0);
	d_ptr = dup;
	while (*src)
		*(dup++) = *(src++);
	*dup = '\0';
	return (d_ptr);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int					i;
	struct s_stock_str	*arr;

	arr = (struct s_stock_str *) malloc((ac + 1) * sizeof(struct s_stock_str));
	if (!arr)
		return (0);
	i = 0;
	while (i < ac)
	{
		arr[i].size = ft_strlen(av[i]);
		arr[i].str = av[i];
		arr[i].copy = ft_strdup(av[i]);
		i++;
	}
	arr[i] = (struct s_stock_str){0, 0, 0};
	return (arr);
}
