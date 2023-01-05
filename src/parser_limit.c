/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_limit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:13:33 by arobu             #+#    #+#             */
/*   Updated: 2023/01/04 22:06:10 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

int	check_int_max(char **split_args, int args_size)
{
	int		i;
	long	number;

	i = 0;
	while (i < args_size)
	{
		number = ft_atoi_long(split_args[i]);
		if (number > INT_MAX || number < INT_MIN)
			return (1);
		i++;
	}
	return (0);
}