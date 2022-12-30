/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 20:32:05 by arobu             #+#    #+#             */
/*   Updated: 2022/12/08 04:35:23 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_atoi(const char *s)
{
	unsigned int	sum;
	int				sign;

	sum = 0;
	sign = 1;
	while (ft_isspace3(*s))
		s++;
	if (*s == '-')
		sign = -1;
	if (*s == '+' || *s == '-')
		s++;
	while (*s)
	{
		if (ft_isdigit(*s))
			sum = sum * 10 + (*s - '0');
		else
			break ;
		s++;
	}
	if (sum > INT_MAX && sign == 1)
		return (-1);
	if (sum > 2147483648 && sign == -1)
		return (0);
	return (sign * sum);
}
