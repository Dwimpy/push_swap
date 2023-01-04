/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:38:52 by arobu             #+#    #+#             */
/*   Updated: 2023/01/03 23:42:34 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/queue.h"

void	display_queue(t_queue *queue)
{
	t_node	*first;

	first = queue->front;
	ft_printf("Node Values: \n");
	while (first != NULL)
	{
		ft_printf("Data: %d\t", first->data);
		ft_printf("Index: %d\n", first->index);
		first = first->next;
	}
}