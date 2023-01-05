/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_limit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:13:33 by arobu             #+#    #+#             */
/*   Updated: 2023/01/05 14:22:36 by arobu            ###   ########.fr       */
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

void	is_empty_argv(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) == 0 && argv[i][0] == '\0')
		{
			ft_putstr_fd("Error\n", 2);
			exit(1);
		}
		i++;
	}
}
