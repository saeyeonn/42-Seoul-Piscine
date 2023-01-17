/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:18:34 by saelim            #+#    #+#             */
/*   Updated: 2022/09/12 20:20:47 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_dec_base_to(char *arr, long long dec_num, char *base_to, int count);

long long	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (-1);
			j++;
		}
		if (base[i] == '-' || base[i] == '+'
			|| (9 <= base[i] && base[i] <= 13) || base[i] == ' ')
			return (-1);
		i++;
	}
	return (i);
}

long long	ft_find_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

long long	ft_atoi(char *num, char *base, long long from_len)
{
	long long	i;
	long long	nbr;
	long long	sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while ((9 <= num[i] && num[i] <= 13) || num[i] == ' ')
		i++;
	while (num[i] == '+' || num [i] == '-')
	{
		if (num[i] == '-')
			sign *= -1;
		i++;
	}
	while (num[i] && ft_find_index(num[i], base) != -1)
	{
		nbr = nbr * from_len + ft_find_index(num[i], base);
		i++;
	}
	return (sign * nbr);
}

long long	ft_count(long long dec_num, long long to_len)
{
	long long	count;

	count = 0;
	if (dec_num == 0)
		return (1);
	if (dec_num < 0)
	{
		count = 1;
		dec_num *= -1;
	}
	while (dec_num > 0)
	{
		dec_num = dec_num / to_len;
		count++;
	}
	return (count);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long long	from_len;
	long long	to_len;
	long long	dec_num;
	long long	count;
	char		*arr;

	from_len = ft_check_base(base_from);
	to_len = ft_check_base(base_to);
	if (from_len <= 1 || to_len <= 1)
		return (0);
	dec_num = ft_atoi(nbr, base_from, from_len);
	count = ft_count(dec_num, to_len);
	arr = (char *) malloc(sizeof(char) * (count + 1));
	if (!arr)
		return (0);
	arr[count] = '\0';
	if (dec_num < 0)
	{
		arr[0] = '-';
		dec_num *= -1;
		count *= -1;
	}
	arr = ft_dec_base_to(arr, dec_num, base_to, count);
	return (arr);
}
