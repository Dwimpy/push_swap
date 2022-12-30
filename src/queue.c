/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 00:59:01 by arobu             #+#    #+#             */
/*   Updated: 2022/12/30 01:56:37 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/queue.h"

t_node *new_node(int value)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = value;
	new_node->cost_a = 0;
	new_node->cost_b = 0;
	new_node->index = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
}

t_queue	*create_queue()
{
	t_queue *queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	queue->front = NULL;
	queue->rear = NULL;
	queue->largest_index = 0;
	queue->lowest_index = 0;
	queue->operations = 0;
	queue->size = 0;
}

int	is_empty(t_queue *queue)
{
	if (queue->size == 0)
		return (1);
	else
		return(0);
}

void	enqueue(t_queue *queue, int	value)
{
	t_node	*node;

	node = new_node(value);
	
	if (is_empty(queue))
	{
		queue->front = node;
		queue->rear = node;
	}
	else
	{
		node -> prev = queue -> rear;
		queue -> rear -> next = node;
		queue -> rear = queue -> rear -> next;
		
	}
	queue->size++;
}

void	dequeue(t_queue *queue)
{
	t_node	*head;

	if (is_empty(queue))
		return ;
	head = queue->front;
	if (queue->front->next != NULL)
	{
		queue -> front = queue -> front -> next;
		queue -> front -> prev = NULL;
	}
	else 
	{
		queue -> front = NULL;
		queue -> rear = NULL;
	}

	queue->size--;
	free(head);
}