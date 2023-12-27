/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoh <mnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 13:11:08 by mnoh              #+#    #+#             */
/*   Updated: 2023/08/10 19:52:44 by mnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_ascending(int *tab, int length, int (*f)(int, int))
{
	int	idx;

	idx = -1;
	while (++idx < length - 1)
		if (f(tab[idx], tab[idx + 1]) > 0)
			return (0);
	return (1);
}

int	is_descending(int *tab, int length, int (*f)(int, int))
{
	int	idx;

	idx = -1;
	while (++idx < length - 1)
		if (f(tab[idx], tab[idx + 1]) < 0)
			return (0);
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	if (is_ascending(tab, length, f))
		return (1);
	else if (is_descending(tab, length, f))
		return (1);
	else
		return (0);
}
