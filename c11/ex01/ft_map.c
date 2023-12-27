/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoh <mnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:29:18 by mnoh              #+#    #+#             */
/*   Updated: 2023/08/10 19:52:36 by mnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	idx;
	int	*res;

	res = (int *)malloc(sizeof(int) * length);
	if (!res)
		return (res);
	idx = -1;
	while (++idx < length)
		res[idx] = f(tab[idx]);
	return (res);
}
