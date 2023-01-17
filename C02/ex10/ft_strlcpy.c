/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:35:40 by saelim            #+#    #+#             */
/*   Updated: 2022/08/29 16:14:23 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}

unsigned int	ft_strlcpy(char	*dest, char	*src, unsigned int size)
{
	int	len;

	len = ft_strlen(src);
	while (*src && size-- > 1)
		*(dest++) = *(src++);
	*dest = '\0';
	return (len);
}
