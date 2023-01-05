/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rrr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:15:33 by arobu             #+#    #+#             */
/*   Updated: 2023/01/04 23:13:19 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rrr(t_push_swap **data)
{
	r_rotate((**data).stack_a);
	r_rotate((**data).stack_b);
	if (!(*data)->is_checker)
		ft_printf("rrr\n");
	(*data)->operation_count--;
}