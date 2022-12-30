/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_specifier_percent.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arobu <arobu@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 12:52:43 by arobu             #+#    #+#             */
/*   Updated: 2022/11/21 20:16:21 by arobu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_validate_specifier_percent(t_fields *field)
{
	if (field -> flags.plus)
		field -> flags.plus = 0;
	if (field -> flags.hash)
		field -> flags.hash = 0;
	if (field -> flags.space)
		field -> flags.space = 0;
	if (field -> flags.zero)
		field -> flags.zero = 0;
}
