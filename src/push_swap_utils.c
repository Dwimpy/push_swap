/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 13:08:54 by arobu             #+#    #+#             */
/*   Updated: 2023/01/03 16:02:37 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_to_b(t_push_swap **data)
{
	int	pushed;
	int	i;
	int	stack_size;
	
	pushed = 0;
	i = 0;
	stack_size = (*data)->stack_a->size;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*data)->stack_a->front->index <= stack_size / 2)
		{
			pb(data);
			pushed++;
		}
		else
			ra(data);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		pb(data);
		pushed++;
	}
}