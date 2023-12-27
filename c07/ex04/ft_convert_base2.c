/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoh <mnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 13:26:15 by mnoh              #+#    #+#             */
/*   Updated: 2023/08/07 23:03:41 by mnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base, int from);
int	base_check(char *base, int n);

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	dec_to_n(char *base, int nbr, int n)
{
	if (nbr < 0)
		return (base[-(nbr % n)]);
	else
		return (base[nbr % n]);
}

char	*ft_putnbr_base(char *arr, int nbr, char *base, int to)
{
	int	idx;

	idx = 0;
	if (nbr == 0)
		arr[idx++] = base[0];
	while (nbr != 0)
	{
		arr[idx++] = dec_to_n(base, nbr, to);
		nbr /= to;
	}
	arr[idx] = '\0';
	return (arr);
}

char	*ft_r_strcpy(int dec, char *arr)
{
	char	*res;
	int		len;
	int		idx;

	len = ft_strlen(arr);
	if (dec < 0)
		len++;
	res = (char *)malloc(sizeof(char) * len + 1);
	if (!res)
		return (0);
	idx = -1;
	res[len] = '\0';
	while (++idx < ft_strlen(arr))
		res[len - 1 - idx] = arr[idx];
	if (dec < 0)
		res[0] = '-';
	return (res);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		dec;
	int		from;
	int		to;
	char	arr[40];

	from = ft_strlen(base_from);
	to = ft_strlen(base_to);
	if (!base_check(base_from, from) || !base_check(base_to, to))
		return (0);
	dec = ft_atoi_base(nbr, base_from, from);
	ft_putnbr_base(arr, dec, base_to, to);
	return (ft_r_strcpy(dec, arr));
}
