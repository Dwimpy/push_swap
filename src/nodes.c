/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:44:26 by arobu             #+#    #+#             */
/*   Updated: 2023/01/02 15:37:52 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/queue.h"

t_node	*swap_nodes(t_node *node1, t_node *node2)
{
	t_node	*tmp;

	tmp = node2->next;
	node2 -> next = node1;
	node1 -> next = tmp;
	return (node2);
}

t_node	*copy_node(t_node *node)
{
	t_node	*c_node;

	c_node = new_node(node->data);
	c_node->cost_a = node->cost_a;
	c_node->cost_b = node->cost_b;
	c_node->index = node->index;
	return (c_node);
}

int	*copy_queue(t_queue *stack)
{
	int		*arr;
	t_node	*first;
	int		i;
	
	arr = (int *)malloc(sizeof(int) * stack->size);
	first = stack->front;
	i = 0;
	while (first != NULL)
	{
		arr[i] = first->data;
		first = first -> next;
		i++;
	}
	return (arr);
}