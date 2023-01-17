/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saelim <saelim@student.42.seoul.kr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 20:34:23 by saelim            #+#    #+#             */
/*   Updated: 2022/09/12 14:54:01 by saelim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_word(char str, char *charset)
{
	int	i;

	i = -1;
	if (str == '\0')
		return (-1);
	while (charset[++i])
		if (str == charset[i])
			return (-1);
	return (0);
}

int	ft_wordcount(char *str, char *charset)
{
	int	i;
	int	wordcount;

	i = -1;
	wordcount = 0;
	while (str[++i])
		if (ft_is_word(str[i], charset) == 0
			&& ft_is_word(str[i + 1], charset) == -1)
			wordcount++;
	return (wordcount);
}

int	ft_wordlen(char *str, char *charset, int index)
{
	int	len;

	len = 0;
	while (ft_is_word(str[index++], charset) == 0)
		len++;
	return (len);
}

char	**ft_mksplit(char *str, char *charset, char **arr, int count)
{
	int	i;
	int	j;
	int	s_index;
	int	wordlen;

	i = 0;
	s_index = 0;
	while (str[s_index] && count-- > 0)
	{
		j = 0;
		while (ft_is_word(str[s_index], charset) == -1)
			s_index++;
		wordlen = ft_wordlen(str, charset, s_index);
		arr[i] = (char *) malloc(sizeof(char) * (wordlen + 1));
		if (!arr[i])
			return (0);
		while (wordlen-- > 0)
			arr[i][j++] = str[s_index++];
		arr[i][j] = '\0';
		i++;
	}
	arr[i] = 0;
	return (arr);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		wordcount;

	wordcount = ft_wordcount(str, charset);
	arr = (char **) malloc(sizeof(char *) * (wordcount + 1));
	if (!arr)
		return (0);
	arr = ft_mksplit(str, charset, arr, wordcount);
	return (arr);
}
