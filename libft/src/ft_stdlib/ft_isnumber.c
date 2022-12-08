/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 01:16:23 by arobu             #+#    #+#             */
/*   Updated: 2022/12/08 06:52:45 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../include/libft.h"
#include "../../include/ft_printf.h"

int	ft_isnumber(char *str)
{
	int	i;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (!ft_isspace3(str[i]) && !ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}