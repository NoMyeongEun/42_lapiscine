/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnoh <mnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:08:41 by mnoh              #+#    #+#             */
/*   Updated: 2023/08/10 15:02:28 by mnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	find_operator(char *op)
{
	char	*op_list;
	int		idx;

	if (op[0] == '\0' || op[1] != '\0')
		return (-1);
	op_list = "+-*/%";
	idx = -1;
	while (op_list[++idx] != '\0')
		if (*op == op_list[idx])
			return (idx);
	return (-1);
}

int	check_error(int num2, int operator)
{
	if (operator == -1)
		write(1, "0", 1);
	else if (operator == 3 && num2 == 0)
		write(1, "Stop : division by zero", 23);
	else if (operator == 4 && num2 == 0)
		write(1, "Stop : modulo by zero", 21);
	else
		return (0);
	return (1);
}
