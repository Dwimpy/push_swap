/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 00:56:06 by arobu             #+#    #+#             */
/*   Updated: 2023/01/03 23:39:48 by arobu            ###   ########.fr       */
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
	display_queue(data->stack_a);
	ft_printf("\nOperations Count: %d\n", data->operation_count);

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
	i = -1;
	while (++i < input_data->size)
		enqueue((*data)->stack_a, input_data->arguments[i]);
}