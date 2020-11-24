/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 19:50:04 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/24 20:15:00 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_lexer.h"

/*
** This function escapes a character following a backslash
*/

void	escape_char(char **input, char **stack)
{
	(*input)++;
	if (**input)
		*stack = eat(*stack, input);
}
