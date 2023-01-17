/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:35:34 by saelim            #+#    #+#             */
/*   Updated: 2022/08/29 18:50:02 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char	*dest, char	*src)
{
	char	*d_ptr;

	d_ptr = dest;
	while (*d_ptr)
		d_ptr++;
	while (*src)
		*(d_ptr++) = *(src++);
	*d_ptr = '\0';
	return (dest);
}