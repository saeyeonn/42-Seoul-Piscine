/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:20:23 by saelim            #+#    #+#             */
/*   Updated: 2022/09/11 21:26:55 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	ft_check_base(char *base);

char	*ft_dec_base_to(char *arr, long long dec_num, char *base_to, int count)
{
	long long	to_len;
	int			i;
	int			size;

	to_len = ft_check_base(base_to);
	i = 0;
	if (count < 0)
	{
		i = 1;
		count *= -1;
	}
	size = count;
	while (i < size)
	{
		arr[count - 1] = base_to[dec_num % to_len];
		dec_num = dec_num / to_len;
		i++;
		count--;
	}
	return (arr);
}
