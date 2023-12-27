/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoh <mnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:02:09 by mnoh              #+#    #+#             */
/*   Updated: 2023/08/10 20:01:49 by mnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int argc, char **argv)
{
	int	(*fp_operate[5])(int, int);
	int	num1;
	int	num2;
	int	operator;

	if (argc != 4)
		return (0);
	fp_operate[0] = ft_sum;
	fp_operate[1] = ft_sub;
	fp_operate[2] = ft_mul;
	fp_operate[3] = ft_div;
	fp_operate[4] = ft_mod;
	operator = find_operator(argv[2]);
	num1 = ft_atoi(argv[1]);
	num2 = ft_atoi(argv[3]);
	if (check_error(num2, operator) == 0)
		ft_putnbr(fp_operate[operator](num1, num2));
	write(1, "\n", 1);
	return (0);
}
