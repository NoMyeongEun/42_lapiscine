/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoh <mnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 15:48:16 by mnoh              #+#    #+#             */
/*   Updated: 2023/08/09 12:06:11 by mnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putnbr(int n)
{
	int	digit;

	if (n != 0)
	{
		digit = '0' + n % 10;
		ft_putnbr(n / 10);
		write(1, &digit, 1);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	while ((*par).str != 0)
	{
		write(1, (*par).str, (*par).size);
		write(1, "\n", 1);
		if ((*par).size == 0)
			write(1, "0", 1);
		else
			ft_putnbr((*par).size);
		write(1, "\n", 1);
		write(1, (*par).copy, (*par).size);
		write(1, "\n", 1);
		par++;
	}
}
