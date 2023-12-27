/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoh <mnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 18:12:08 by mnoh              #+#    #+#             */
/*   Updated: 2023/08/01 08:33:57 by mnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_word(char *str)
{
	if (*str >= '0' && *str <= '9')
		return (1);
	else if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z'))
		return (1);
	else
		return (0);
}

char	*ft_strcapitalize(char *str)
{
	char	*res;
	int		flag;

	res = str;
	flag = 0;
	while (*str != '\0')
	{
		if (flag != is_word(str))
		{
			flag = 1;
			if (*str >= 'a' && *str <= 'z')
				*str -= 32;
		}
		else if (flag == is_word(str) && *str >= 'A' && *str <= 'Z')
			*str += 32;
		if (!is_word(str))
			flag = 0;
		str++;
	}
	return (res);
}
