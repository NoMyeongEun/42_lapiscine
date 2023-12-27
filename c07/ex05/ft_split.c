/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoh <mnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 17:07:38 by mnoh              #+#    #+#             */
/*   Updated: 2023/08/08 21:57:48 by mnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char str, char *charset)
{
	while (*charset != '\0')
		if (*charset++ == str)
			return (1);
	return (0);
}

int	word_count(char *str, char *charset)
{
	int	cnt;

	cnt = 0;
	while (*str != '\0')
	{
		if (!is_sep(*str, charset))
			if (*(str + 1) == '\0' || is_sep(*(str + 1), charset))
				cnt++;
		str++;
	}
	return (cnt);
}

char	*ft_strcpy(char *str, int start, int end)
{
	char	*res;
	int		idx;

	res = (char *)malloc(sizeof(char) * (end - start + 1) + 1);
	if (!res)
		return (res);
	idx = -1;
	while (++idx <= (end - start))
		res[idx] = str[start + idx];
	*(res + end - start + 1) = '\0';
	return (res);
}

void	find_word(char *str, char *charset, int *start, int *end)
{	
	int	idx2;

	idx2 = *end;
	*end = -1;
	while (str[++idx2] != '\0')
	{
		if (*start <= *end)
			break ;
		if (!is_sep(str[idx2], charset))
		{
			if (idx2 == 0 || is_sep(str[idx2 - 1], charset))
				*start = idx2;
			if (str[idx2 + 1] == '\0' || is_sep(str[idx2 + 1], charset))
				*end = idx2;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		start;
	int		end;
	int		idx;

	res = (char **)malloc(sizeof(char *) * (word_count(str, charset) + 1));
	if (!res)
		return (res);
	start = 0;
	end = -1;
	idx = -1;
	while (++idx < word_count(str, charset))
	{
		find_word(str, charset, &start, &end);
		res[idx] = ft_strcpy(str, start, end);
		if (!res[idx])
			return (0);
	}
	res[idx] = 0;
	return (res);
}
