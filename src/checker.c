/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 22:19:49 by arobu             #+#    #+#             */
/*   Updated: 2023/01/05 03:31:19 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	checker(t_parsed_data *input_data)
{
	t_push_swap	*data;
	char		*cmd;
	int			i;

	i = 0;
	checker_init(&data, input_data);
	while (1)
	{
		cmd = get_next_line(STDIN_FILENO);
		if (cmd == NULL)
			break;
		read_and_execute(&data, cmd);
	}
	if (checker_is_sorted(data) == 1 && is_empty((data)->stack_b))
		ft_printf("\033[0;32mOK\n\033[0;39m");
	else
		ft_printf("\033[0;91mKO\n\033[0;39m");
	ft_free_ps_data(data);
}
void	read_and_execute(t_push_swap **data, char	*str)
{
	if (ft_strncmp(str, "pa\n", 3) == 0)
		pa(data);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		pb(data);
	else if (ft_strncmp(str, "sa\n", 3) == 0)
		sa(data);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		sb(data);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
		ss(data);
	else if (ft_strncmp(str, "ra\n", 3) == 0)
		ra(data);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		rb(data);
	else if (ft_strncmp(str, "rra\n", 3) == 0)
		rra(data);
	else if (ft_strncmp(str, "rrb\n", 3) == 0)
		rrb(data);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
		rr(data);
	else if (ft_strncmp(str, "rrr\n", 3) == 0)
		rrr(data);
	else
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

void	checker_init(t_push_swap **data, t_parsed_data *input_data)
{
	int	i;

	(*data) = (t_push_swap *)malloc(sizeof(t_push_swap));
	(*data)->stack_a = create_queue();
	(*data)->stack_b = create_queue();
	(*data)->highest_index = 0;
	(*data)->lowest_index = 0;
	(*data)->operation_count = 0;
	(*data)->is_checker = 1;
	i = -1;
	while (++i < input_data->size)
		enqueue((*data)->stack_a, input_data->arguments[i]);
}

int		checker_is_sorted(t_push_swap *data)
{
	t_node	*node;

	node = (*data).stack_a->front;
	while (node->next!= NULL)
	{
		if (node->data > node -> next -> data)
			return (0);
		node = node -> next;
	}	
	return (1);
}