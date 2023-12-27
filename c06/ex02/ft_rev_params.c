/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoh <mnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:47:16 by mnoh              #+#    #+#             */
/*   Updated: 2023/08/06 18:32:38 by mnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	idx;
	int	idx2;

	idx = argc;
	while (--idx > 0)
	{
		idx2 = -1;
		while (argv[idx][++idx2] != '\0')
			write(1, &argv[idx][idx2], 1);
		write(1, "\n", 1);
	}
	return (0);
}
