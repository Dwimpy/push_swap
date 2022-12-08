/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort_queue.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 03:09:31 by arobu             #+#    #+#             */
/*   Updated: 2022/12/08 06:29:57 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/queue.h"

void	merge_lists(t_qnode **first, t_qnode **second, t_qnode **tmp, t_qnode **merged);

t_qnode *merge(t_qnode *first, t_qnode *second)
{
	t_qnode *merged;
	t_qnode *tmp;
	
	merged = (t_qnode *)malloc(sizeof(t_qnode));
	tmp = (t_qnode *)malloc(sizeof(t_qnode));
	
	merged = tmp;
	while (first != NULL && second != NULL)
	{
		if (first -> value <= second -> value)
		{
			tmp -> next_node = first;
			first = first -> next_node;
		}
		else
		{
			tmp -> next_node = second;
			second = second -> next_node;
		}
		tmp = tmp->next_node;
	}
	while (first != NULL)
	{
		tmp -> next_node = first;
		first = first -> next_node;
		tmp = tmp -> next_node;
	}
	while (second != NULL)
	{
		tmp -> next_node = second;
		second = second -> next_node;
		tmp = tmp -> next_node;
	}
	return (merged -> next_node);
}

void	merge_lists(t_qnode **first, t_qnode **second, t_qnode **tmp, t_qnode **merged)
{
	while (first != NULL && second != NULL)
	{
		if ((*first) -> value <= (*second)-> value)
		{
			(*tmp)-> next_node = *first;
			*first = (*first) -> next_node;
		}
		else
		{
			(*tmp) -> next_node = (*second);
			*second = (*second) -> next_node;
		}
		*tmp = (*tmp)->next_node;
	}
	while (first != NULL)
	{
		(*tmp) -> next_node = (*first);
		(*first) = (*first) -> next_node;
		(*tmp) = (*tmp) -> next_node;
	}
	while (second != NULL)
	{
		(*tmp) -> next_node = (*second);
		(*second) = (*second) -> next_node;
		(*tmp) = (*tmp) -> next_node;
	}
}

t_qnode *get_middle_node(t_qnode *head)
{
	t_qnode	*slow;
	t_qnode *fast;

	slow = head;
	fast = head -> next_node;
	while (!slow -> next_node && (!fast && !fast -> next_node))
	{
		slow = slow -> next_node;
		fast = fast -> next_node -> next_node;
	}
	return (slow);
}

t_qnode *sort(t_qnode *head)
{
	t_qnode *final_head;

	if (head -> next_node == NULL)
		return head;
	
	t_qnode	*mid = (t_qnode *)malloc(sizeof(t_qnode));
	t_qnode *new_head = (t_qnode *)malloc(sizeof(t_qnode));
	mid = get_middle_node(head);
	new_head = mid -> next_node;
	mid -> next_node = NULL;
	final_head = merge(sort(head), sort(new_head));
	return (final_head);
}