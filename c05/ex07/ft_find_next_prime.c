/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoh <mnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 23:52:36 by mnoh              #+#    #+#             */
/*   Updated: 2023/08/04 19:35:41 by mnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_find_next_prime(int nb)
{
	long long	i;
	int			prime;

	prime = nb;
	while (prime > 2)
	{
		i = 2;
		while (i * i <= prime)
		{
			if (prime % i == 0)
				break ;
			i++;
		}
		if (i * i > prime)
			return (prime);
		prime++;
	}
	return (2);
}
