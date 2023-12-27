/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoh <mnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 21:47:34 by mnoh              #+#    #+#             */
/*   Updated: 2023/08/07 21:42:01 by mnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	ft_strcat(char *src, char *str)
{
	while (*src != '\0')
		src++;
	while (*str != '\0')
		*src++ = *str++;
	*src = '\0';
}

char	*ft_alloc(int size, char **strs, char *sep)
{
	char	*res;
	int		idx;
	int		len;

	idx = -1;
	len = ft_strlen(sep) * (size - 1);
	while (++idx < size)
		len += ft_strlen(strs[idx]);
	res = (char *)malloc(sizeof(char *) * (len + 1));
	return (res);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	char	*start;
	int		idx;

	if (size == 0)
	{
		res = (char *)malloc(1);
		*res = 0;
		return (res);
	}
	res = ft_alloc(size, strs, sep);
	if (!res)
		return (res);
	start = res;
	idx = -1;
	res[0] = '\0';
	while (++idx < size)
	{
		ft_strcat(res, strs[idx]);
		if (idx != size - 1)
			ft_strcat(res, sep);
	}
	return (start);
}
