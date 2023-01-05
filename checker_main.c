/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:22:28 by arobu             #+#    #+#             */
/*   Updated: 2023/01/05 04:25:39 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/checker.h"

int	main(int argc, char **argv)
{
	t_parsed_data	parsed_data;
	int				is_checker;

	is_checker = 1;
	parse_arguments(argc, argv, is_checker);
	parsed_data = get_data(argc, argv);
	checker(&parsed_data);
	free_parser(&parsed_data);
}