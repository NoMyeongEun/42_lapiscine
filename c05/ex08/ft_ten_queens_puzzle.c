/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoh <mnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 06:19:39 by mnoh              #+#    #+#             */
/*   Updated: 2023/08/05 23:06:30 by mnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

int	abs(int n)
{
	if (n < 0)
		return (n);
	else
		return (-n);
}

int	promising(int i, int *col)
{
	int	j;

	j = 1;
	while (j < i)
	{
		if (col[i] == col[j] || abs(col[i] - col[j]) == abs(i - j))
			return (0);
		j++;
	}
	return (1);
}

void	print_solution(int *col)
{
	char	c;
	int		idx;

	idx = 1;
	while (idx < 11)
	{
		c = '0' + col[idx];
		write(1, &c, 1);
		idx++;
	}
	write(1, "\n", 1);
}

void	recursive_ten_queens(int i, int *col, int *cnt)
{
	int	idx2;

	if (i == 0)
		*cnt = 0;
	if (promising(i, col))
	{
		if (i == 10)
		{
			print_solution(col);
			*cnt += 1;
		}
		else
		{
			idx2 = 0;
			while (idx2 < 10)
			{
				col[i + 1] = idx2;
				recursive_ten_queens(i + 1, col, cnt);
				idx2++;
			}
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	cnt;
	int	col[11];

	recursive_ten_queens(0, col, &cnt);
	return (cnt);
}
