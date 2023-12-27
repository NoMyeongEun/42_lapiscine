/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoh <mnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:33:25 by mnoh              #+#    #+#             */
/*   Updated: 2023/08/04 15:30:40 by mnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	write_num(int n)
{
	int	digit;

	if (n != 0)
	{
		digit = '0' + n % 10;
		if (n < 0)
			digit = '0' - n % 10;
		write_num(n / 10);
		write(1, &digit, 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
		write(1, "0", 1);
	if (nb < 0)
		write(1, "-", 1);
	write_num(nb);
}
