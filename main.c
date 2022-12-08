/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:10:09 by arobu             #+#    #+#             */
/*   Updated: 2022/12/08 06:23:47 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/queue.h"
#include "include/push_swap.h"

int main(int argc, char *argv[])
{

	if (argc == 1)
		return (0);
	push_swap(argc, argv);

	// int keys[] = {1, 2};
	// int keys2[] = {3, 4, 5, 6};
	// int n = sizeof(keys)/sizeof(keys[0]);
	// int n2 = sizeof(keys2)/sizeof(keys[0]);

	// t_queue *queue1 = create_queue();
	// t_queue *queue2 = create_queue();
	// int i = -1;
	// while (++i < n)
	// 	enqueue(queue1, keys[i]);
	// i = -1;
	// while (++i < n2)
	// 	enqueue(queue2, keys2[i]);
	// swap_top_ab(queue1, queue2);
	// ft_printf("%d\n", queue1 ->front -> value);
	// ft_printf("%d\n", queue1 ->rear ->value);

	//enqueue(queue2, 3);
	//ft_printf("%d\n", queue2->front->value);
	//ft_printf("%d\n", queue1->rear->value);
	//ft_printf("%d\n", queue1->rear->value);

	return (0);
}
