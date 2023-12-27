/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoh <mnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 12:41:00 by mnoh              #+#    #+#             */
/*   Updated: 2023/08/01 11:02:55 by mnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	idx;

	idx = 0;
	while (dest[idx] != '\0')
		idx++;
	while (*src != '\0')
	{
		dest[idx] = *src;
		src++;
		idx++;
	}
	dest[idx] = '\0';
	return (dest);
}
