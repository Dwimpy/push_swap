/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 00:56:06 by arobu             #+#    #+#             */
/*   Updated: 2023/01/02 13:13:27 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/parser.h"

void	push_swap(t_parsed_data *data)
{	
	t_push_swap *ps_data;
	int i;

	ps_data = (t_push_swap *)malloc(sizeof(t_push_swap));
	ps_data->stack_a = create_queue();
	ps_data->stack_b = create_queue();
	i = -1;
	while (++i < data->size)
		enqueue(ps_data->stack_a, data->arguments[i]);
	assign_index_to_nodes(&ps_data);
	i = 0;
	while (i < ps_data->stack_a->size)
	{
	ft_printf("%d\t", ps_data->stack_a->front->data);

	ft_printf("%d\n", ps_data->stack_a->front->index);
		ps_data->stack_a->front = ps_data->stack_a->front->next;
		i++;
	}

}