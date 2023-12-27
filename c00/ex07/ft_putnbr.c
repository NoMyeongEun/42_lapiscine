/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoh <mnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 23:08:26 by mnoh              #+#    #+#             */
/*   Updated: 2023/07/23 18:13:01 by mnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	count_num(int num)
{
	char	d2;

	d2 = '0' + num % 10;
	if (num < 0)
	{
		d2 = '0' - num % 10;
	}
	num /= 10;
	if (num != 0)
	{
		count_num(num);
	}
	write(1, &d2, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
	}
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	count_num(nb);
}
