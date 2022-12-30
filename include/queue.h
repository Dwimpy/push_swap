/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 00:51:00 by arobu             #+#    #+#             */
/*   Updated: 2022/12/30 01:58:16 by arobu            ###   ########.fr       */
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
t_node *new_node(int value);
void	enqueue(t_queue *queue, int	value);
void	dequeue(t_queue *queue);

#endif