/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:57:23 by arobu             #+#    #+#             */
/*   Updated: 2022/12/06 22:16:36 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#ifndef RUN
# define RUN 64
#endif

#include "queue.h"
#include "../libft/include/ft_printf.h"

typedef struct	s_push_swap
{
	t_queue	*stack_a;
	t_queue	*stack_b;
}				t_push_swap;

void	push_swap(int argc, char **argv);
int		get_minrun(int n);

#endif