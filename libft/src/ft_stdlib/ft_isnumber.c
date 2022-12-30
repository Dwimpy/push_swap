/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 01:16:23 by arobu             #+#    #+#             */
/*   Updated: 2022/12/17 07:08:25 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../include/libft.h"
#include "../../include/ft_printf.h"

int	ft_isnumber(char *str)
{
	int	i;
	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}