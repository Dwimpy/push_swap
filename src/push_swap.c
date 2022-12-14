/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:27:14 by arobu             #+#    #+#             */
/*   Updated: 2022/12/08 06:48:30 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_swap(int argc, char **argv)
{
	t_push_swap push_swap_data;
	
	initialize_data(&push_swap_data);
	parse_args(&push_swap_data, argc, argv);
	if (check_duplicates(push_swap_data.stack_a -> front) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	push_swap_data.min_run = get_minrun(push_swap_data.sample_size);
	initialize_runs(&push_swap_data);
}
