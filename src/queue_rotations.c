/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_rotations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:06:13 by arobu             #+#    #+#             */
/*   Updated: 2022/12/06 17:23:12 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/queue.h"

/**
 * Function to rotate the list upwards.
 * Shifts the entire queue by 1 element.
 * The first element becomes the last.
 * @param Queue List to perform the rotation
 * @return (void)
*/
void	rotate(t_queue *queue)
{
	if (queue -> front != NULL)
	{
		enqueue(queue, queue->front->value);
		dequeue(queue);
	}
}

/**
 * Performs the rotate() function on both queues
 * passed as arguments at the same time.
 * @param Queue_a Queue_a to rotate.
 * @param Queue_b Queue_b to rotate.
 * @return (void)
*/
void	rotate_ab(t_queue *queue_a, t_queue *queue_b)
{
	rotate(queue_a);
	rotate(queue_b);
}

/**
 * Function to rotate the list downwards.
 * Shifts the entire queue by 1 element.
 * The last element becomes the first.
 * @param Queue List to perform reverse rotation.
 * @return (void)
*/

void	reverse_rotate(t_queue *queue)
{
	t_qnode	*new_last;
	t_qnode *new_first;
	
	if (is_empty(queue) \
	|| queue -> front -> next_node == NULL \
	|| queue -> rear -> prev_node == NULL)
		return ;

	new_first = queue -> rear; 
	queue -> rear = queue -> rear -> prev_node;
	new_first -> next_node = queue -> front;
	queue -> front -> prev_node = new_first;
	queue -> front = queue -> front -> prev_node;
	queue -> rear -> next_node = NULL;
	queue -> front -> prev_node = NULL;
}

/**
 * Performs the reverse_rotate() function on 
 * both queues passed as arguments at the same time.
 * @param Queue_a Queue_a to reverse rotate.
 * @param Queue_b Queue_b to reverse rotate.
 * @return (void)
*/
void	reverse_rotate_ab(t_queue *queue_a, t_queue *queue_b)
{
	reverse_rotate(queue_a);
	reverse_rotate(queue_b);
}
