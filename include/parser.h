/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 23:33:53 by arobu             #+#    #+#             */
/*   Updated: 2023/02/27 14:01:02 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include "ft_printf.h"

typedef struct s_constraints
{
	int		has_duplicates;
	int		invalid_input;
	int		no_arguments;
	int		invalid_limit;
	int		is_checker;
}			t_constraints;

typedef struct s_parsed_data
{
	int		*arguments;
	size_t	size;
}				t_parsed_data;

void			parse_arguments(int argc, char **argv, int is_checker);

char			*create_argument(int argc, char **argv);

t_parsed_data	get_data(int argc, char **argv);
void			is_empty_argv(int argc, char **argv);
int				invalid_input(t_constraints c);
int				is_valid_data(char **split_args, int args_size);
int				check_duplicates(char **split_args, int args_size);
int				check_int_max(char **split_args, int args_size);
int				get_size(char **split_args);
int				is_sorted(char **split_args, int args_size);
void			ft_free(char **str);
void			free_parser(t_parsed_data *p_data);

#endif
