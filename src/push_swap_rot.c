/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:13:10 by arobu             #+#    #+#             */
/*   Updated: 2023/01/02 13:21:54 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_push_swap **data)
{
	rotate((*data)->stack_a);
}

void	rb(t_push_swap **data)
{
	rotate((*data)->stack_b);
}

void	rr(t_push_swap **data)
{
	rotate((*data)->stack_a);
	rotate((*data)->stack_b);
}

void	rra(t_push_swap **data)
{
	r_rotate((*data)->stack_a);
}

void	rrb(t_push_swap **data)
{
	r_rotate((*data)->stack_b);
}