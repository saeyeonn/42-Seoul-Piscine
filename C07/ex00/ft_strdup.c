/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 20:22:29 by saelim            #+#    #+#             */
/*   Updated: 2022/09/07 21:16:02 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*(str++))
		len++;
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*dup;
	char	*d_ptr;

	dup = (char *) malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dup)
		return (0);
	d_ptr = dup;
	while (*src)
		*(dup++) = *(src++);
	*dup = '\0';
	return (d_ptr);
}
