/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:12:56 by arobu             #+#    #+#             */
/*   Updated: 2022/12/08 04:29:06 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_H
# define QUEUE_H

# include "../libft/include/ft_printf.h"

typedef struct s_qnode	t_qnode;

typedef struct s_qnode
{
	int			value;
	t_qnode		*next_node;
	t_qnode		*prev_node;
}				t_qnode;

typedef struct s_queue
{
	t_qnode		*front;
	t_qnode		*rear;
	int			size;
}				t_queue;

t_qnode		*new_node(int value);
t_queue		*create_queue(void);

void		enqueue(t_queue *queue, int value);
void		dequeue(t_queue *queue);

void		swap_top(t_queue *queue);
void		push_top(t_queue *destination, t_queue *source);

void		rotate(t_queue *queue);
void		reverse_rotate(t_queue *queue);

void		swap_top_ab(t_queue *queue_a, t_queue *queue_b);
void		reverse_rotate_ab(t_queue *queue_a, t_queue *queue_b);

int			is_empty(t_queue *queue);
int			queueSize(t_queue *queue);

#endif
