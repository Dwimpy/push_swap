/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 16:56:31 by arobu             #+#    #+#             */
/*   Updated: 2023/01/05 14:38:48 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/queue.h"

void	rotate(t_queue *stack)
{
	t_node	*new_last;

	if (is_empty(stack) || stack->front == stack->rear)
		return ;
	new_last = stack -> front;
	stack->front = stack -> front -> next;
	stack -> rear -> next = new_last;
	new_last -> prev = stack -> rear;
	stack -> rear = stack -> rear -> next;
	stack -> rear -> next = NULL;
	stack -> front -> prev = NULL;
}

void	r_rotate(t_queue *stack)
{
	t_node	*new_first;

	if (is_empty(stack) || stack->front == stack->rear)
		return ;
	new_first = stack -> rear;
	stack -> rear = stack -> rear -> prev;
	new_first -> next = stack -> front;
	stack -> front -> prev = new_first;
	stack -> front = stack -> front -> prev;
	stack -> rear -> next = NULL;
	stack -> front -> prev = NULL;
}

void	swap(t_queue *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (is_empty(stack) || stack->front == stack->rear)
		return ;
	first = stack -> front;
	second = first -> next;
	third = second -> next;
	third -> prev = first;
	first -> next = third;
	first -> prev = second;
	second -> next = first;
	second -> prev = NULL;
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
		new_node->next = destination->front;
		destination->front->prev = new_node;
		destination->front = new_node;
	}
	destination->size++;
	dequeue(source);
}
