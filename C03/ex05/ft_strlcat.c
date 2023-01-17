/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 20:17:24 by saelim            #+#    #+#             */
/*   Updated: 2022/09/03 18:33:34 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char	*str)
{
	int	len;

	len = 0;
	while (*(str++))
		++len;
	return (len);
}

unsigned int	ft_strlcat(char	*dest, char	*src, unsigned int size)
{
	unsigned int	d_len;
	unsigned int	s_len;

	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	if (size <= d_len)
		return (s_len + size);
	while (*dest)
		++dest;
	while (*src && size > d_len + 1)
	{
		*(dest++) = *(src++);
		size--;
	}
	*dest = '\0';
	return (s_len + d_len);
}
