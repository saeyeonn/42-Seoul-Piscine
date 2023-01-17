/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 21:16:14 by saelim            #+#    #+#             */
/*   Updated: 2022/09/11 21:43:39 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		*dest = src[i];
		dest++;
		i++;
	}
	return (dest);
}

int	ft_sum_len(int size, char **strs, char *sep)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < size)
		sum += ft_strlen(strs[i++]);
	sum += ft_strlen(sep) * (size - 1);
	return (sum);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		sum;
	char	*arr;
	char	*a_ptr;

	i = 0;
	if (size == 0)
	{
		a_ptr = (char *)malloc(sizeof(char) * 1);
		*a_ptr = 0;
		return (a_ptr);
	}
	sum = ft_sum_len(size, strs, sep);
	arr = (char *)malloc(sizeof(char) * (sum + 1));
	a_ptr = arr;
	i = 0;
	while (i < size)
	{
		arr = ft_strcpy(arr, strs[i]);
		if (i != size - 1)
			arr = ft_strcpy(arr, sep);
		i++;
	}
	*arr = 0;
	return (a_ptr);
}
