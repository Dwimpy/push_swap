/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 21:27:14 by arobu             #+#    #+#             */
/*   Updated: 2022/12/06 22:29:08 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_swap(int argc, char **argv)
{
	t_push_swap push_swap_data;
	
}
int		get_minrun(int n)
{
	int r;

	r = 0;
	while (n >= 64)
	{
		r = r | (n & 0x01);
		ft_printf("%d", r);
		n >>= 1;
	}
	return (n + r);
}
