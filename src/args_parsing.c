/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:04:55 by arobu             #+#    #+#             */
/*   Updated: 2022/12/08 06:49:05 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	parse_split_number(t_push_swap **data, char **argv);
static void	parse_argv(t_push_swap **data, int argc, char **argv);
void	ft_free(t_push_swap **data, char **str);

int	parse_args(t_push_swap *data, int argc, char **argv)
{
	char	*trimmed_str;

	trimmed_str = ft_strtrim_char(argv[1], ' ');
	if (trimmed_str[0] == '\0' || !ft_isnumber(trimmed_str))
	{
		ft_putstr_fd("Error\n", 2);
		free((*data).stack_a);
		free((*data).stack_b);
		exit(EXIT_FAILURE);
	}
	else if (argc == 2)
		parse_split_number(&data, argv);
	else 
		parse_argv(&data, argc, argv);
	free(trimmed_str);
	return (0);
}

static void	parse_split_number(t_push_swap **data, char **argv)
{
	char	**numbers;
	int		i;
	int		number;
	
	i = -1;
	numbers = ft_split(argv[1],' ');
	while(numbers[++i] != NULL)
	{
		if (ft_isnumber(numbers[i]))
		{
			enqueue((*data)->stack_a, ft_atoi(numbers[i]));
			(**data).sample_size++;
		}
		else
		{
			ft_putstr_fd("Error \n", 2);
			ft_free(data, numbers);
			exit(EXIT_FAILURE);
		}
	}
	ft_free(NULL, numbers);
}

static void	parse_argv(t_push_swap **data, int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (ft_isnumber(argv[i]))
		{
			enqueue((*data)->stack_a, ft_atoi(argv[i]));
			(**data).sample_size++;
		}
		else
		{
			ft_putstr_fd("Error\n", 2);
			ft_free(data, NULL);
			exit(EXIT_FAILURE);
		}
	}
}

int	check_duplicates(t_qnode *head)
{
	t_qnode	*sorted_list;

	sorted_list = sort(head);
	while(sorted_list -> next_node != NULL)
	{
		if (sorted_list -> value == sorted_list -> next_node -> value)
			return (1);
		sorted_list = sorted_list -> next_node;
	}
	return (0);
}

void	ft_free(t_push_swap **data, char **str)
{
	int i;
	
	if (str)
	{
		while (str[i] != NULL)
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
	if (data != NULL)
	{
		while ((*data) -> stack_a -> front != NULL)
			dequeue((*data) -> stack_a);
		free((*data) -> stack_a);
		free((*data) -> stack_b);
	}
}
