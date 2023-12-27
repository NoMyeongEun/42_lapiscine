/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoh <mnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:20:13 by mnoh              #+#    #+#             */
/*   Updated: 2023/08/02 19:37:46 by mnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if (*str >= 32 && *str <= 126)
			write(1, str, 1);
		else
		{
			write(1, "\\", 1);
			write(1, &"0123456789abcdef"[(unsigned char)*(str) / 16], 1);
			write(1, &"0123456789abcdef"[(unsigned char)*(str) % 16], 1);
		}
		str++;
	}
}
