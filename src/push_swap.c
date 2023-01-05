/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:49:17 by arobu             #+#    #+#             */
/*   Updated: 2023/01/04 23:12:22 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/parser.h"

void	push_swap(t_parsed_data *input_data)
{	
	t_push_swap *ps_data;
	t_push_swap *data;
	int			*costs;

	costs = (int *)malloc(sizeof(int) * 2);
	push_swap_init(&data, input_data);
	assign_index_to_nodes(&data);
	push_to_b(&data);
	sort_initial_values(&data);
	while (!is_empty(data->stack_b))
	{
		calculate_cost(&data);
		get_best_move(&data, &costs);
		execute_best_move(&data, costs);
	}
	rotate_stack_to_lowest(&data);
	free(costs);
	ft_free_ps_data(data);
}

void	push_swap_init(t_push_swap **data, t_parsed_data *input_data)
{
	int	i;

	(*data) = (t_push_swap *)malloc(sizeof(t_push_swap));
	(*data)->stack_a = create_queue();
	(*data)->stack_b = create_queue();
	(*data)->highest_index = 0;
	(*data)->lowest_index = 0;
	(*data)->operation_count = 0;
	(*data)->is_checker = 0;
	i = -1;
	while (++i < input_data->size)
		enqueue((*data)->stack_a, input_data->arguments[i]);
}

void	ft_free_ps_data(t_push_swap *data)
{
	while (!is_empty(data->stack_a))
		dequeue(data->stack_a);
	while (!is_empty(data->stack_b))
		dequeue(data->stack_b);
	free(data->stack_a);
	free(data->stack_b);
	free(data);
}