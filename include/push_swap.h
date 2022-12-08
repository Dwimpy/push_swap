/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:57:23 by arobu             #+#    #+#             */
/*   Updated: 2022/12/08 06:03:42 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#ifndef RUN
# define RUN 64
#endif

#include "queue.h"
#include "../libft/include/ft_printf.h"

typedef struct	s_run
{
	int			*array;
	size_t		size;
}				t_run;

typedef struct	s_push_swap
{
	int			sample_size;
	t_queue		*stack_a;
	t_queue		*stack_b;
	t_run		*runs;
	int			run_count;
	int			min_run;
}				t_push_swap;

void		push_swap(int argc, char **argv);

t_qnode 	*sort(t_qnode *head);

int			parse_args(t_push_swap *data, int argc, char **argv);
int			get_minrun(int n);
int			check_duplicates(t_qnode *head);

void		initialize_runs(t_push_swap *data);
void		initialize_data(t_push_swap *data);

#endif