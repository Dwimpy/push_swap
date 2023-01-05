/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:13:10 by arobu             #+#    #+#             */
/*   Updated: 2023/01/05 14:38:40 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_push_swap **data)
{
	rotate((**data).stack_a);
	if (!(*data)->is_checker)
		ft_printf("ra\n");
	(*data)->operation_count++;
}

void	rb(t_push_swap **data)
{
	rotate((**data).stack_b);
	if (!(*data)->is_checker)
		ft_printf("rb\n");
	(*data)->operation_count++;
}

void	rr(t_push_swap **data)
{
	rotate((**data).stack_a);
	rotate((**data).stack_b);
	if (!(*data)->is_checker)
		ft_printf("rr\n");
	(*data)->operation_count--;
}

void	rra(t_push_swap **data)
{
	r_rotate((**data).stack_a);
	if (!(*data)->is_checker)
		ft_printf("rra\n");
	(*data)->operation_count++;
}

void	rrb(t_push_swap **data)
{
	r_rotate((**data).stack_b);
	if (!(*data)->is_checker)
		ft_printf("rrb\n");
	(*data)->operation_count++;
}
