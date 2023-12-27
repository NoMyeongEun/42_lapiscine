/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoh <mnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 22:24:35 by mnoh              #+#    #+#             */
/*   Updated: 2023/08/02 19:35:33 by mnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;
	unsigned int	len;

	idx = 0;
	len = 0;
	while (src[len] != '\0')
	{
		if (size != 0 && idx < size - 1)
		{	
			*dest = src[len];
			dest++;
			idx++;
		}
		len++;
	}
	if (size != 0)
		*dest = '\0';
	return (len);
}
