/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:10:09 by arobu             #+#    #+#             */
/*   Updated: 2022/12/05 21:02:04 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/queue.h"

int main(int argc, char *argv[])
{

	int keys[] = {1, 2, 3};
	int keys2[] = {4, 5, 6};
	int n = sizeof(keys)/sizeof(keys[0]);

	t_queue *queue1 = create_queue();
	t_queue *queue2 = create_queue();
	int i = -1;
	while (++i < n)
		enqueue(queue1, keys[i]);
	i = -1;
	while (++i < n)
		enqueue(queue2, keys2[i]);
	reverse_rotate(queue1);
	ft_printf("%d\n", queue1->front->value);
	ft_printf("%d\n", queue1->rear->value);

	return (0);
}