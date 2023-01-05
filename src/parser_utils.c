/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 08:25:03 by arobu             #+#    #+#             */
/*   Updated: 2023/01/04 22:06:56 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/parser.h"

int get_size(char **split_args)
{
	int	i;

	i = 0;
	while (split_args[i] != NULL)
		i++;
	return (i);
}

int	invalid_input(t_constraints c)
{
	return (c.has_duplicates == 1 || c.invalid_input == 1 \
		|| c.no_arguments == 1 || c.invalid_limit == 1);
}

int is_sorted(char **split_args, int args_size)
{
	int		i;

	i = 0;
	while (i < args_size - 1)
	{
		if (ft_atoi(split_args[i]) > ft_atoi(split_args[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

t_parsed_data	get_data(int argc, char **argv)
{
	char	*data;
	char	**str;
	int		size;
	int		i;
	t_parsed_data parsed_data;
	i = 0;
	parsed_data.size = 0;
	data = create_argument(argc, argv);
	str = ft_split(data, ' ');
	size = get_size(str);
	parsed_data.arguments = (int *)malloc(sizeof(int) * (size));
	while (str[i] != NULL)
	{
		parsed_data.arguments[i] = ft_atoi(str[i]);
		parsed_data.size++;
		i++;
	}
	free(data);
	ft_free(str);
	return (parsed_data);
}

void	ft_free(char **str)
{
	int i;
	
	i = 0;
	if (str)
	{
		while (str[i] != NULL)
		{
			free(str[i]);
			i++;
		}
		free(str);
	}
}