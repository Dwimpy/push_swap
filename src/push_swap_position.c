/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_position.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 03:14:28 by arobu             #+#    #+#             */
/*   Updated: 2023/01/03 03:45:27 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	assign_position(t_push_swap **data)
{
	t_node	*a;
	t_node	*b;
	int		i;

	i = 0;
	a = (*data)->stack_a->front;
	b = (*data)->stack_b->front;
	while (a != NULL)
	{
		a -> position = i;
		i++;
		a = a->next;
	}	
	i = 0;
	while (b != NULL)
	{
		b -> position = i;
		i++;
		b = b->next;
	}	
}

int	find_sorted_position(t_queue **data, int b_index)
{
	t_node	*a;
	int		target_index = 
	a = (*data)->front;
	while (a != NULL)
	{
		if (a -> index > b_index && a -> index < sorted_pos)
		{
			sorted_pos = a -> index;
			sorte
		}
	}
}