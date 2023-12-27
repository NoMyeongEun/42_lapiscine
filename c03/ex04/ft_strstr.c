/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoh <mnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:21:48 by mnoh              #+#    #+#             */
/*   Updated: 2023/08/01 13:59:46 by mnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		idx;

	if (to_find[0] == '\0')
		return (str);
	while (*str != '\0')
	{
		idx = 0;
		if (*str == to_find[0])
		{
			while ((str[idx] == to_find[idx]) && to_find[idx] != '\0')
				idx++;
			if (to_find[idx] == '\0')
				return (str);
		}
		str++;
	}
	return (0);
}
