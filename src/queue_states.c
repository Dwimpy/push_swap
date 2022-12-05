/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_states.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:16:21 by arobu             #+#    #+#             */
/*   Updated: 2022/12/05 21:16:47 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/queue.h"

/**
 * Helper fucking to check if the specified
 * queue is empty.
 * @param Queue List to check whether it empty.
 * @return Returns 1 if empty or 0 if not empty
*/
int	is_empty(t_queue *queue)
{
	return (queue->rear == NULL);
}

/**
 * Function to return the size of the List.
 * @param Queue List to count elements.
 * @return Returns the number of elements in the List.
*/
int	queue_size(t_queue *queue)
{
	t_qnode	*tmp_node;
	int		count;

	count = 0;
	if (is_empty(queue))
		return (0);
	tmp_node = queue->front;
	while (++count && tmp_node -> next_node != NULL)
		tmp_node = tmp_node -> next_node;
	return (count);
}
