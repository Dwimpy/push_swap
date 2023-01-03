/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 00:54:38 by arobu             #+#    #+#             */
/*   Updated: 2023/01/02 22:01:49 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "queue.h"
#include "parser.h"

typedef struct s_push_swap
{
	t_queue *stack_a;
	t_queue *stack_b;
	int		lowest_index;
	int		highest_index;
	int		operation_count;
}				t_push_swap;

void	push_swap(t_parsed_data *input_data);
int		*bubble_sort(t_push_swap *data);
void	assign_index_to_nodes(t_push_swap **data);
void	push_to_b(t_push_swap **data);
void	sort_initial_values(t_push_swap **data);
void	push_swap_init(t_push_swap **data, t_parsed_data *input_data);
void	calculate_cost(t_push_swap **data);
void	get_best_move(t_push_swap **data, int **arr);
void	execute_best_move(t_push_swap **data, int *arr);
void	rotate_stack_to_lowest(t_push_swap **data);

void	sa(t_push_swap **data);
void	sb(t_push_swap **data);
void	ss(t_push_swap **data);
void	pa(t_push_swap **data);
void	pb(t_push_swap **data);
void	ra(t_push_swap **data);
void	rb(t_push_swap **data);
void	rr(t_push_swap **data);
void	rra(t_push_swap **data);
void	rrb(t_push_swap **data);
void	rrr(t_push_swap **data);
#endif