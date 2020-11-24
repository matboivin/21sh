/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 19:50:04 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/24 20:59:15 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_lexer.h"

/*
** This function escapes a character following a backslash
*/

int		escape_char(char **input, char **stack)
{
	(*input)++;
	if (**input)
	{
		*stack = eat(*stack, input);
		return (0);
	}
	return (1);
}
