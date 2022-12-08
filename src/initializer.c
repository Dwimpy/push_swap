/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:47:10 by arobu             #+#    #+#             */
/*   Updated: 2022/12/08 06:15:20 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		get_run_count(t_push_swap data);

void	initialize_data(t_push_swap *data)
{
	(*data).sample_size = 0;
	(*data).stack_a = create_queue();
	(*data).stack_b = create_queue();
	(*data).min_run = 0;
	(*data).runs = NULL;
}

void	initialize_runs(t_push_swap *data)
{
	t_push_swap *tmp;
	int			run_count;
	
	tmp = data;
	run_count = get_run_count(*data);
}

int		get_run_count(t_push_swap data)
{
	int	run_count;

	if (data.sample_size % data.min_run != 0)
		run_count = 1;
	else
		run_count = 0;
	run_count = data.sample_size / data.min_run;
	return (run_count);
}

int		get_minrun(int n)
{
	int r;

	r = 0;
	while (n >= 64)
	{
		r = r | (n & 0x01);
		n >>= 1;
	}
	return (n + r);
}
