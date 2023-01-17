/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:48:51 by saelim            #+#    #+#             */
/*   Updated: 2022/08/31 20:10:28 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strlowcase1(char	*str)
{
	char	*s_ptr;

	s_ptr = str;
	while (*s_ptr)
	{
		if ('A' <= *s_ptr && *s_ptr <= 'Z')
			*s_ptr += 32;
		s_ptr++;
	}
	return (str);
}

char	*ft_strcapitalize(char	*str)
{
	int	i;

	i = 0;
	ft_strlowcase1(str);
	if ('a' <= str[0] && str[0] <= 'z')
		str[0] -= 32;
	while (str[++i])
		if ((str[i - 1] < '0' || ('9' < str[i - 1] && str[i - 1] < 'A')
				|| ('Z' < str[i - 1] && str[i - 1] < 'a') || str[i - 1] > 'z')
			&& ('a' <= str[i] && str[i] <= 'z'))
			str[i] -= 32;
	return (str);
}
