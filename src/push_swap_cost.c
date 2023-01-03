/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cost.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:43:09 by arobu             #+#    #+#             */
/*   Updated: 2023/01/03 00:56:20 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
int		get_cost_a_out_bounds(t_node *a, t_node *b);
int		get_cost_a_in_bounds(t_node *a, int lowest_index);
void	update_cost_a(t_node	**b, int cost_a, int size_a);
void	update_cost_b(t_node	**b, int cost_b, int size_b);

void	calculate_cost(t_push_swap **data)
{
	t_node	*a;
	t_node	*b;
	int		cost_a;
	int		cost_b;
	
	a = (*data)->stack_a->front;
	b = (*data)->stack_b->front;
	cost_b = 0;
	while (b != NULL)
	{
		if (b->index > (*data)->lowest_index && \
			b->index < (*data)->highest_index)
			cost_a = get_cost_a_out_bounds(a, b);
		else
			cost_a = get_cost_a_in_bounds(a, (*data)->lowest_index);
		update_cost_a(&b, cost_a, (*data)->stack_a->size);
		update_cost_b(&b, cost_b, (*data)->stack_b->size);
		b = b->next;
		cost_b++;
	}
}

int	get_cost_a_out_bounds(t_node *a, t_node *b)
{
	int	cost_a;
	
	cost_a = 1;
	while (a->next != NULL)
	{
		if (b->index > a->index && b->index < a->next->index) 
			break;
		cost_a++;
		a = a->next;
	}
	return (cost_a);
}

int	get_cost_a_in_bounds(t_node *a, int lowest_index)
{
	int	cost_a;
	
	cost_a = 0;
	while (a->index != lowest_index)
	{
		cost_a++;
		a = a->next; 
	}
	return (cost_a);
}

void	update_cost_a(t_node	**b, int cost_a, int size_a)
{
	if (cost_a > size_a / 2)
		(*b)->cost_a = cost_a - size_a;
	else
		(*b)->cost_a = cost_a;
}

void	update_cost_b(t_node	**b, int cost_b, int size_b)
{
	if (cost_b > size_b / 2)
		(*b)->cost_b = cost_b - size_b;
	else
		(*b)->cost_b = cost_b;
}
