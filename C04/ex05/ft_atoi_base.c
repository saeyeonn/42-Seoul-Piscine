/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:30:58 by saelim            #+#    #+#             */
/*   Updated: 2022/09/03 21:53:27 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_checkbase(char	*base)
{
	int		len;
	char	*b_ptr;

	len = 0;
	while (*base)
	{
		b_ptr = base;
		if (*base == '\t' || *base == '\r' || *base == '\n' || *base == '\f'
			|| *base == '\v' || *base == ' ' || *base == '-' || *base == '+')
			return (-1);
		while (*(b_ptr++))
			if (*base == *b_ptr)
				return (-1);
		base++;
		len++;
	}
	return (len);
}

int	ft_strcheck(char c, char *base)
{
	int	i;

	i = -1;
	while (base[++i])
		if (c == base[i])
			return (1);
	return (0);
}

int	ft_convertindex(char *str, char *base, int b_len)
{
	int		num;
	int		i;
	int		index;

	i = -1;
	num = 0;
	while (str[++i])
	{
		if (ft_strcheck(str[i], base) == 0)
			return (num);
		index = 0;
		while (str[i] != base[index])
			index++;
		num = num * b_len + index;
	}
	return (num);
}

int	ft_atoi_base(char	*str, char	*base)
{
	int	sign;
	int	num;
	int	b_len;

	sign = 1;
	b_len = ft_checkbase(base);
	if (b_len <= 1)
		return (0);
	while (*str == '\t' || *str == '\r' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == ' ')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	num = ft_convertindex(str, base, b_len);
	return (sign * num);
}
