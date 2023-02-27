/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:26:14 by arobu             #+#    #+#             */
/*   Updated: 2023/02/27 14:04:28 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "get_next_line.h"
# include "push_swap.h"

void	checker(t_parsed_data *input_data);
void	checker_init(t_push_swap **data, t_parsed_data *input_data);
int		checker_is_sorted(t_push_swap *data);
void	read_and_execute(t_push_swap **data, char	*str);
void	exit_incorrect_instruction(void);

#endif
