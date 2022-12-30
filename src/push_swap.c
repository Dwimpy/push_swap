/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 00:56:06 by arobu             #+#    #+#             */
/*   Updated: 2022/12/30 01:58:52 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/parser.h"

void	push_swap(t_parsed_data *data)
{	
	t_node *node;
	t_queue *queue;
	node = new_node(100);
	queue = create_queue();

	enqueue(queue, node->data);
	dequeue(queue);
	ft_printf("%d", queue->front->data);
}