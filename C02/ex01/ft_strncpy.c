/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:04:15 by saelim            #+#    #+#             */
/*   Updated: 2022/09/04 00:12:17 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	char				*d_ptr;
	unsigned int		i;

	d_ptr = dest;
	i = 0;
	while (*src && i < n)
	{
		*(d_ptr++) = *(src++);
		i++;
	}
	while (i < n)
	{
		*(d_ptr++) = 0;
		i++;
	}
	return (dest);
}
