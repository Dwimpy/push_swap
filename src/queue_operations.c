/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:56:31 by arobu             #+#    #+#             */
/*   Updated: 2023/01/01 17:48:38 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/queue.h"

void	rotate(t_queue *stack)
{
	t_node	*first;
	t_node	*last;
	
	if (is_empty(stack) || stack->front == stack->rear)
		return ;
	first = stack->front;
	last = stack->rear;
	stack->front = stack->front->next;
	stack->front->prev = NULL;
	stack->rear->next = first;
	stack->rear = stack->rear->next;
	stack->rear->prev = last;
	stack->rear->next = NULL;
}

void	r_rotate(t_queue *stack)
{
	t_node	*last;

	if (is_empty(stack) || stack->front == stack->rear)
		return ;
	last = stack->rear;
	stack->rear = stack->rear->prev;
	stack->rear->next = NULL;
	stack->front->prev = last;
	last->next = stack->front;
	stack->front = last;
	stack->front->prev = NULL;
}

void	swap(t_queue *stack)
{
	t_node	*first;
	t_node	*second;

	if (is_empty(stack) || stack->front == stack->rear)
		return ;
	first = stack->front;
	second = stack->front->next;
	stack->front = stack->front->next;
	first->next = stack->front->next;
	stack->front = first;
	stack->front->prev = second;
	second->next = stack->front;
	second->prev = NULL;
	stack->front = second;
}

void	push(t_queue *destination, t_queue *source)
{
	t_node	*first;
	t_node	*new_node;
	

	if (is_empty(source))
		return ;
	first = source->front;
	new_node = copy_node(first);
	if (is_empty(destination))
	{
		destination->front = new_node;
		destination->rear = new_node;
	}
	else
	{
		destination->front->prev = new_node;
		new_node->next = destination->front;
		destination->front = new_node;
	}
	dequeue(source);
}