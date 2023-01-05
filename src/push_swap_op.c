/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_op.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:09:34 by arobu             #+#    #+#             */
/*   Updated: 2023/01/05 14:40:12 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_push_swap **data)
{
	swap((*data)->stack_a);
	if (!(*data)->is_checker)
		ft_printf("sa\n");
	(*data)->operation_count++;
}

void	sb(t_push_swap **data)
{
	swap((*data)->stack_b);
	if (!(*data)->is_checker)
		ft_printf("sb\n");
	(*data)->operation_count++;
}

void	ss(t_push_swap **data)
{
	swap((*data)->stack_a);
	swap((*data)->stack_b);
	if (!(*data)->is_checker)
		ft_printf("ss\n");
	(*data)->operation_count--;
}

void	pa(t_push_swap **data)
{
	push((*data)->stack_a, (*data)->stack_b);
	if (!(*data)->is_checker)
		ft_printf("pa\n");
	(*data)->operation_count++;
}

void	pb(t_push_swap **data)
{
	push((*data)->stack_b, (*data)->stack_a);
	if (!(*data)->is_checker)
		ft_printf("pb\n");
	(*data)->operation_count++;
}
