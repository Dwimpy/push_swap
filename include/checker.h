/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:26:14 by arobu             #+#    #+#             */
/*   Updated: 2023/01/04 23:03:00 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"
#include "../include/push_swap.h"

void	checker(t_parsed_data *input_data);
void	checker_init(t_push_swap **data, t_parsed_data *input_data);
int		checker_is_sorted(t_push_swap *data);
void	read_and_execute(t_push_swap **data, char	*str);
