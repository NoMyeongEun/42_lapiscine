/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoh <mnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 14:52:00 by mnoh              #+#    #+#             */
/*   Updated: 2023/08/09 00:03:20 by mnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strdup(char *str)
{
	int		len;
	char	*res;

	len = ft_strlen(str);
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (res);
	while (*str != '\0')
		*res++ = *str++;
	*res = '\0';
	return (res - len);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			idx;
	t_stock_str	*res;

	res = malloc(sizeof(t_stock_str) * (ac + 1));
	idx = -1;
	while (++idx < ac)
	{
		res[idx].size = ft_strlen(av[idx]);
		res[idx].str = av[idx];
		res[idx].copy = ft_strdup(av[idx]);
	}
	res[ac].str = 0;
	return (res);
}
