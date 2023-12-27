/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoh <mnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:40:34 by mnoh              #+#    #+#             */
/*   Updated: 2023/08/10 23:19:32 by mnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
/*
void	ft_print_address(unsigned long long *addr)
{
	unsigned int	idx;

	idx = 0;
	while (idx < 16)
	{
		
	}
}*/

void	ft_print_hex(unsigned char *addr)
{
	char	arr[40];
	int		i;
	int		addr_i;
	char	*base;
	
    base = "0123456789abcdef";
	i = -1;
	while (++i < 32)
		arr[i] = ' ';
	i = 0;
	addr_i = 0;
	while (i < 44 && addr[addr_i] != '\0')
	{
		arr[i] = base[addr[addr_i] / 16];
		arr[i + 1] = base[addr[addr_i] % 16];
		if (i % 4 != 0)
			arr[++i + 1] = ' ';
		i += 2;
		addr_i++;
	}
	write(1, arr, 40);
}

void	ft_print_str(unsigned long long *str)
{
	int	idx;

	idx = -1;
	while (str[++idx] != '\0' && idx < 16)
	{
		if (str[idx] >= 32 && str[idx] <= 126)
			write(1, &str[idx], 1);
		else
			write(1, ".", 1);
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned long long	*c;
	unsigned int		i;

	c = (unsigned long long *)addr;
	i = 0;
	while (i < size)
	{
	//	ft_print_address(c + i);
//		write(1, ": ", 2);
		 ft_print_hex((unsigned char *)c + i);
		write(1, "\n", 1);
		ft_print_str(c + i);
		write(1, "\n", 1);
		i += 16;
	}
	return (0);
}


int main() {
	// Exercise 12
	char arr[] = "Bonjour les aminches\t\n\tc\a est fou\ttout\tce qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";
	if (ft_print_memory(arr, 92) != arr)
		return -1;
	char brr[] = "Chuncheon is better than Seoul!\200:)\377;)";
	ft_print_memory(brr, 38);
	ft_print_memory(brr, 10);
	ft_print_memory(brr, 0);
	for (int i = 13; i < 24; ++i)
		brr[i] = '\0';
	ft_print_memory(brr, 37);
	ft_print_memory(brr, 37);
	return 0;
}
