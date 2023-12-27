/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoh <mnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:07:31 by mnoh              #+#    #+#             */
/*   Updated: 2023/08/10 15:01:00 by mnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	sign;
	int	res;

	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	res = 0;
	while (*str >= '0' && *str <= '9')
	{
		res *= 10;
		res += (sign * (*str - '0'));
		str++;
	}
	return (res);
}

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
	if (nb < 0)
		write(1, "-", 1);
	if (nb == 0)
		write(1, "0", 1);
	write_num(nb);
}
