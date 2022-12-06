/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_push_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:19:46 by arobu             #+#    #+#             */
/*   Updated: 2022/12/06 19:57:52 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/queue.h"

/**
 * Function to swap the contents of
 * the first two nodes of a queue.
 * Does nothing if the queue is empty.
 * @param Queue Queue to perform swap.
 * @return (void)
*/
void	swap_top(t_queue *queue)
{
	int	tmp_data;

	if (is_empty(queue) || queue->front->next_node == NULL)
		return ;
	tmp_data = queue->front->next_node->value;
	queue->front->next_node->value = queue->front->value;
	queue->front->value = tmp_data;
}

/**
 * Function to perform swap_top on both
 * queues passed as arguments at the same time.
 * @param Queue_a Queue_a to perform swap.
 * @param Queue_b Queue_b to perform swap.
 * @return (void)
*/
void	swap_top_ab(t_queue *queue_a, t_queue *queue_b)
{
	swap_top(queue_a);
	swap_top(queue_b);
}

/**
 * Function to take the head node in source
 * and set it to the head node in destination.
 * Pushes the first element in source to destination.
 * @param source Source queue
 * @param destination Destination queue
 * @return (void)
*/
void	push_top(t_queue *destination, t_queue *source)
{
	t_qnode	*tmp_node;

	if (is_empty(source))
		return ;
	if (is_empty(destination) && source -> front -> next_node == NULL)
	{
		enqueue(destination, source -> front -> value);
		dequeue(source);
	}
	else if (source -> front -> next_node == NULL)
	{
		tmp_node = new_node(source -> front -> value);
		tmp_node -> next_node = destination -> front;
		destination -> front = tmp_node;
		dequeue(source);
	}
	else
	{
		tmp_node = new_node(source -> front -> value);
		tmp_node -> next_node = destination -> front;
		destination -> front -> prev_node = tmp_node;
		destination -> front = destination -> front -> prev_node;
		dequeue(source);
	}
}
