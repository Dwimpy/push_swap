/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_cost_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 19:06:07 by arobu             #+#    #+#             */
/*   Updated: 2023/01/03 23:35:56 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

#include "../include/push_swap.h"

static void	cost_efficient_rev_rotate(t_push_swap **data, int **arr)
{
	while ((*arr)[0] < 0 && (*arr)[1] < 0)
	{
		(*arr)[0] += 1;
		(*arr)[1] += 1;
		rrr(data);
	}
}

static void cost_efficient_rotate(t_push_swap **data, int **arr)
{
	while ((*arr)[0] > 0 && (*arr)[1] > 0)
	{
		(*arr)[0] -= 1;
		(*arr)[1] -= 1;
		rr(data);
	}
}

static void cost_eff_rotate_a(t_push_swap **data, int **arr)
{
	while ((*arr)[0])
	{
		if ((*arr)[0] > 0)
		{
			(*arr[0]) -= 1;
			ra(data);
		}
		else if ((*arr)[0] < 0)
		{
			(*arr)[0] += 1;
			rra(data);
		}
	}
}

static void cost_eff_rotate_b(t_push_swap **data, int **arr)
{
	while ((*arr)[1])
	{
		if ((*arr)[1] > 0)
		{
			(*arr)[1]--;
			rb(data);
		}
		else if ((*arr)[1] < 0)
		{
			(*arr)[1]++;
			rrb(data);
		}
	}
}

void	execute_best_move(t_push_swap **data, int *arr)
{
	if (arr[0] < 0 && arr[1] < 0)
		cost_efficient_rev_rotate(data, &arr);
	else if (arr[0] > 0 && arr[1] > 0)
		cost_efficient_rotate(data, &arr);
	cost_eff_rotate_a(data, &arr);
	cost_eff_rotate_b(data, &arr);
	if ((*data)->stack_b->front->index < (*data)->lowest_index)
		(*data)->lowest_index = (*data)->stack_b->front->index;
	else if ((*data)->stack_b->front->index > (*data)->highest_index)
		(*data)->highest_index = (*data)->stack_b->front->index;
	pa(data);
}