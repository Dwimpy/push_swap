/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 21:03:35 by arobu             #+#    #+#             */
/*   Updated: 2023/01/02 15:42:34 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*bubble_sort(t_push_swap *data)
{
	int	*arr;
	int	i;
	int	j;
	int	tmp;
	
	arr = copy_queue(data->stack_a);
	i = 0;
	while (i < data->stack_a->size)
	{
		j = 0;
		while (j < data->stack_a->size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);	
}

void	assign_index_to_nodes(t_push_swap **data)
{
	int		*arr;
	t_node	*first;
	int		i;
	
	arr = bubble_sort(*data);
	first = (*data)->stack_a->front;
	i = 0;
	while (i < (*data)->stack_a->size)
	{
		first = (*data)->stack_a->front;
		while (first != NULL)
		{
			if (arr[i] == first->data)
			{
				first->index = i + 1;
				i++;
				break ;
			}
			first = first -> next;
		}
	}
	free(arr);
}