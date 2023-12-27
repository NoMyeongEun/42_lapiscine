/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoh <mnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 16:31:14 by mnoh              #+#    #+#             */
/*   Updated: 2023/08/04 21:55:19 by mnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check(char base)
{
	if (base == ' ' || (base >= 9 && base <= 13))
		return (-1);
	else if (base == '+' || base == '-')
		return (1);
	else
		return (0);
}

int	base_check(char *base, int n)
{
	int	i;
	int	j;

	i = 0;
	if (n < 2)
		return (0);
	while (i < n)
	{
		if (check(base[i]) != 0)
			return (0);
		j = i + 1;
		while (j < n)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	n_to_dec(char *str, char *base, int n)
{
	int	res;
	int	n_dex;
	int	idx;

	res = 0;
	idx = -1;
	while (str[++idx] != '\0')
	{
		n_dex = -1;
		while (++n_dex < n)
			if (str[idx] == base[n_dex])
				break ;
		if (n_dex == n)
			break ;
		res *= n;
		res += n_dex;
	}
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int	n;
	int	sign;

	n = 0;
	sign = 1;
	while (base[n] != '\0')
		n++;
	if (!base_check(base, n))
		return (0);
	while (check(*str) == -1)
		str++;
	while (*str != '\0' && check(*str) == 1)
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	return (sign * n_to_dec(str, base, n));
}
