/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 19:36:55 by saelim            #+#    #+#             */
/*   Updated: 2022/09/03 20:08:28 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find(char *str, char *to_find)
{
	char	*f_ptr;

	f_ptr = to_find;
	while (*to_find)
	{
		to_find = f_ptr;
		while (*str && *to_find && *str == *to_find)
		{
			str++;
			to_find++;
		}
		if (!*to_find)
			return (1);
		else
			break ;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	if (!*to_find)
		return (str);
	while (*str)
	{
		if (*str == *to_find)
			if (ft_find(str, to_find))
				return (str);
		str++;
	}
	return (0);
}
