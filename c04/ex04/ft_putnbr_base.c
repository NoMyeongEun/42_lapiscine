/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoh <mnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 15:12:56 by mnoh              #+#    #+#             */
/*   Updated: 2023/08/04 19:18:08 by mnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	cal_base(char *base)
{
	int	n;

	n = 0;
	while (base[n] != '\0')
	{
		if (base[n] == '+' || base[n] == '-')
			return (0);
		n++;
	}
	return (n);
}

int	base_check(char *base, int n)
{
	int	i;
	int	j;

	i = 0;
	if (n < 2)
		return (0);
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	dec_to_n(char *base, int nbr, int n)
{
	if (nbr == 0)
		return ;
	dec_to_n(base, nbr / n, n);
	if (nbr < 0)
		write(1, &base[-(nbr % n)], 1);
	else
		write(1, &base[nbr % n], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	n;

	n = cal_base(base);
	if (!base_check(base, n))
		return ;
	if (nbr == 0)
		write(1, &base[0], 1);
	else
	{
		if (nbr < 0)
			write(1, "-", 1);
		dec_to_n(base, nbr, n);
	}
}	
