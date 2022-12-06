/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:17:30 by arobu             #+#    #+#             */
/*   Updated: 2022/12/06 21:51:57 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/queue.h"

/**
 * Helper function to allocate memory and create
 * a new linked list node. Sets the value property
 * of the node to the value passed as an argument
 * and sets the pointer to the next node to NULL
 * @param value Set the value of the node to the
 * specified argument
 * @return Returns the created node
*/
t_qnode	*new_node(int value)
{
	t_qnode	*node;

	node = (t_qnode *)malloc(sizeof(t_qnode));
	if (!node)
		return (NULL);
	node -> value = value;
	node -> next_node = NULL;
	node -> prev_node = NULL;
	return (node);
}

/**
 * Function to create a linked list queue.
 * Allocates memory and returns the list
 * while setting the front and rear property
 * values to NULL;
 * @param (void)
 * @return Returns the newly created queue.
*/
t_queue	*create_queue(void)
{
	t_queue	*queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (!queue)
		return (NULL);
	queue -> front = NULL;
	queue -> rear = NULL;
	queue -> size = 0;
	return (queue);
}

/**
 * Function to add a new node at the end
 * of the list. If the list is empty it will
 * set both front and rear properties to node
 * else it simply updates the rear node to the new value;
 * @param queue List to be modified
 * @param value Sets the value property of the new node
 * @return (void)
*/
void	enqueue(t_queue *queue, int value)
{
	t_qnode	*node;

	node = new_node(value);
	if (!node)
		return ;
	if (is_empty(queue))
	{
		queue->front = node;
		queue->rear = node;
	}
	else
	{
		node -> prev_node = queue -> rear;
		queue -> rear -> next_node = node;
		queue -> rear = node;
	}
	queue->size++;
}

/**
 * Function to remove a node from the beginning
 * of the list. If the list is empty it will
 * do nothing else it updates the front node to
 * the next value in the list.
 * @param queue List to be modified
 * @details what is this
 * @return (void)
*/
void	dequeue(t_queue *queue)
{
	t_qnode	*current_front;

	if (is_empty(queue))
		return ;
	current_front = queue->front;
	if (queue -> front -> next_node != NULL)
	{
		queue->front = queue->front->next_node;
		queue -> front -> prev_node = NULL;
	}
	else
		queue -> front = NULL;
	if (queue->front == NULL)
		queue->rear = NULL;
	queue->size--;
	free(current_front);
}
