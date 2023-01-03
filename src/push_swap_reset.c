/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_reset.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 21:57:43 by arobu             #+#    #+#             */
/*   Updated: 2023/01/02 22:02:23 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_stack_to_lowest(t_push_swap **data)
{
	t_node	*first;
	int		i;
	
	first = (*data)->stack_a->front;
	i = 0;
	while (first->index != 1)
	{
		i++;
		first = first->next;
	}
	if (i > (*data)->stack_a->size / 2)
	{
		while ((*data)->stack_a->front->index != 1)
			ra(data);
	}
	else
		while ((*data)->stack_a->front->index != 1)
			rra(data);
}