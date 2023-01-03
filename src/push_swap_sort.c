/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:48:00 by arobu             #+#    #+#             */
/*   Updated: 2023/01/02 17:05:25 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_initial_values(t_push_swap **data)
{
	int		highest_index;
	t_node	*first;
	
	first = (*data)->stack_a->front;
	highest_index = 0;
	while (first != NULL)
	{
		if (first->index > highest_index)
			highest_index = first->index;
		first = first->next;
	}
	(*data)->highest_index = highest_index;
	if ((*data)->stack_a->front->index == highest_index)
		ra(data);
	else if ((*data)->stack_a->front->next->index == highest_index)
		rra(data);
	if ((*data)->stack_a->front->index > (*data)->stack_a->front->next->index)
		sa(data);
	(*data)->lowest_index = (*data)->stack_a->front->index;
}
