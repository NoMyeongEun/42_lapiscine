/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoh <mnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:47:32 by mnoh              #+#    #+#             */
/*   Updated: 2023/08/06 18:36:33 by mnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	idx;

	idx = 0;
	while (s1[idx] != '\0' || s2[idx] != '\0')
	{
		if (s1[idx] > s2[idx])
			return (1);
		else if (s1[idx] < s2[idx])
			return (-1);
		idx++;
	}
	return (0);
}

void	ft_sort_params(char **argv, int size)
{
	int		i;
	int		j;
	int		min_idx;
	char	*tmp;

	i = 1;
	while (i < size)
	{
		min_idx = i;
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(argv[j], argv[min_idx]) == -1)
				min_idx = j;
			j++;
		}
		tmp = argv[i];
		argv[i] = argv[min_idx];
		argv[min_idx] = tmp;
		i++;
	}
	return ;
}

void	ft_print_params(int argc, char **argv)
{
	int	idx;
	int	idx2;

	idx = 0;
	while (++idx < argc)
	{
		idx2 = -1;
		while (argv[idx][++idx2] != '\0')
			write(1, &argv[idx][idx2], 1);
		write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	ft_sort_params(argv, argc);
	ft_print_params(argc, argv);
	return (0);
}
