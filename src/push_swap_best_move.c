/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_best_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 18:47:45 by arobu             #+#    #+#             */
/*   Updated: 2023/01/03 01:02:23 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_abs_value(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

void	get_best_move(t_push_swap **data, int **arr)
{
	int		best_move;
	int		cheapest_index;
	t_node	*first;
	
	best_move = INT_MAX;
	cheapest_index = INT_MAX;
	first = (*data)->stack_b->front;
	while (first != NULL)
	{
		if (ft_abs_value(first->cost_a) + ft_abs_value(first->cost_b) < best_move)
		{
			(*arr)[0] = first->cost_a;
			(*arr)[1] = first->cost_b;
			best_move = ft_abs_value(first->cost_a) + ft_abs_value(first->cost_b);
			cheapest_index = first->index;
		}
		first = first->next;
	}

	ft_printf("Cheapest Index: %d\t", cheapest_index);
	ft_printf("Lowest Index: %d\n", (*data)->lowest_index);
}
