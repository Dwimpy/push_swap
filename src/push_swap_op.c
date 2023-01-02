/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:09:34 by arobu             #+#    #+#             */
/*   Updated: 2023/01/02 13:21:31 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_push_swap **data)
{
	swap((*data)->stack_a);
}

void	sb(t_push_swap **data)
{
	swap((*data)->stack_b);
}

void	ss(t_push_swap **data)
{
	swap((*data)->stack_a);
	swap((*data)->stack_b);
}

void	pa(t_push_swap **data)
{
	push((*data)->stack_a, (*data)->stack_b);
}

void	pb(t_push_swap **data)
{
	push((*data)->stack_b, (*data)->stack_a);
}
