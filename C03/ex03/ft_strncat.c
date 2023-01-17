/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:41:06 by saelim            #+#    #+#             */
/*   Updated: 2022/09/03 18:27:43 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*d_ptr;

	d_ptr = dest;
	while (*d_ptr)
		d_ptr++;
	while (*src && nb > 0)
	{
		*(d_ptr++) = *(src++);
		nb--;
	}
	*d_ptr = '\0';
	return (dest);
}
