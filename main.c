/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 00:55:11 by arobu             #+#    #+#             */
/*   Updated: 2023/01/03 03:10:52 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/parser.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_parsed_data parsed_data;

	parse_arguments(argc, argv);
	parsed_data = get_data(argc, argv);
	push_swap(&parsed_data);
	free_parser(&parsed_data);
}