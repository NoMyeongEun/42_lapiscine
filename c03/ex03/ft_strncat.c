/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoh <mnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 13:13:00 by mnoh              #+#    #+#             */
/*   Updated: 2023/08/01 09:31:34 by mnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	idx;
	unsigned int	idx2;

	idx = 0;
	idx2 = 0;
	while (dest[idx] != '\0')
		idx++;
	while (src[idx2] != '\0' && idx2 < nb)
	{
		dest[idx + idx2] = src[idx2];
		idx2++;
	}
	dest[idx + idx2] = '\0';
	return (dest);
}
