/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoh <mnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:47:50 by mnoh              #+#    #+#             */
/*   Updated: 2023/07/25 17:29:14 by mnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	write_num(int num)
{
	char	d2;

	d2 = '0' + num % 10;
	num /= 10;
	if (num != 0)
	{
		write_num(num);
	}
	write(1, &d2, 1);
}

void	write_zero(int num, int mul)
{
	if (num != 0 && num % (mul / 10) == num)
	{
		write(1, "0", 1);
	}
}

int	cal_last_num(int num, int mul)
{
	int	result;

	result = 0;
	while (num != 0)
	{
		mul /= 10;
		result += (10 - num) * mul;
		num--;
	}
	return (result);
}

int	is_comb(int num)
{
	int	digit;
	int	min;

	min = 10;
	while (num != 0)
	{
		digit = num % 10;
		if (digit >= min)
		{
			return (0);
		}
		min = digit;
		num /= 10;
	}
	return (1);
}

void	ft_print_combn(int n)
{
	int	s;
	int	i;
	int	mul;
	int	last_num;

	i = 0;
	mul = 1;
	while (i < n)
	{
		mul *= 10;
		i++;
	}
	s = mul / 100;
	last_num = cal_last_num(n, mul);
	while (s <= last_num)
	{
		if (is_comb(s))
		{
			write_zero(s, mul);
			write_num(s);
			if (s != last_num)
				write(1, ", ", 2);
		}
		s++;
	}
}
