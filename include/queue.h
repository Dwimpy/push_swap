/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 00:51:00 by arobu             #+#    #+#             */
/*   Updated: 2023/01/02 15:41:06 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include "../libft/include/ft_printf.h"

typedef struct s_node t_node;

typedef struct s_node
{
	int		data;
	int		index;
	int		cost_a;
	int		cost_b;
	t_node	*next;
	t_node	*prev;
	
}				t_node;

typedef struct s_queue
{
	t_node	*front;
	t_node	*rear;
	int		size;
	int		largest_index;
	int		lowest_index;
	int		operations;
}				t_queue;

t_queue	*create_queue();
t_node 	*new_node(int value);
t_node	*copy_node(t_node *node);
t_node	*swap_nodes(t_node *node1, t_node *node2);

int		is_empty(t_queue *queue);
int		*copy_queue(t_queue *stack);

void	enqueue(t_queue *queue, int	value);
void	dequeue(t_queue *queue);
void	rotate(t_queue *stack);
void	r_rotate(t_queue *stack);
void	swap(t_queue *stack);
void	push(t_queue *destination, t_queue *source);
void	display_queue(t_queue *queue);

#endif