/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 06:43:50 by arobu             #+#    #+#             */
/*   Updated: 2023/02/27 14:03:00 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	input_checker(t_constraints *constraints, int argc, \
					char **split_args, int args_size);

void	parse_arguments(int argc, char **argv, int is_checker)
{
	char			*args;
	char			**split_args;
	int				args_size;
	t_constraints	constraints;

	constraints = (t_constraints){0, 0, 0, 0, 0};
	constraints.is_checker = is_checker;
	is_empty_argv(argc, argv);
	args = create_argument(argc, argv);
	split_args = NULL;
	args_size = 0;
	if (args != NULL)
	{
		split_args = ft_split(args, ' ');
		args_size = get_size(split_args);
	}
	free(args);
	input_checker(&constraints, argc, split_args, args_size);
	if (invalid_input(constraints))
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	ft_free(split_args);
}

void	input_checker(t_constraints *constraints, int argc, \
					char **split_args, int args_size)
{
	if (argc == 1)
		constraints->no_arguments = 1;
	else if (is_valid_data(split_args, args_size) == 1)
		constraints->invalid_input = 1;
	else if (check_int_max(split_args, args_size) == 1)
		constraints->invalid_limit = 1;
	else if (check_duplicates(split_args, args_size) == 1)
		constraints->has_duplicates = 1;
	else if (is_sorted(split_args, args_size) && !constraints->is_checker)
	{
		ft_free(split_args);
		exit(EXIT_SUCCESS);
	}
}

char	*create_argument(int argc, char **argv)
{
	char	*str;
	char	*tmp;
	int		i;

	str = NULL;
	i = 1;
	if (argc == 2)
		str = ft_strdup(argv[i]);
	if (argc > 2)
	{
		str = ft_strdup(argv[i]);
		while (++i < argc)
		{
			tmp = str;
			str = ft_strjoin_three(str, " ", argv[i]);
			free(tmp);
		}
	}
	return (str);
}

int	is_valid_data(char **split_args, int args_size)
{
	int		i;
	int		invalid;

	i = 0;
	invalid = 0;
	while (i < args_size)
	{
		if (!ft_isnumber(split_args[i]))
			invalid = 1;
		i++;
	}
	return (invalid);
}

int	check_duplicates(char **split_args, int args_size)
{
	int		i;
	int		j;
	int		number;

	i = 0;
	j = 0;
	while (i < args_size - 1)
	{
		j = i + 1;
		number = ft_atoi(split_args[i]);
		while (j < args_size)
		{
			if (number == ft_atoi(split_args[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
