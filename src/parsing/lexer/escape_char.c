/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 19:50:04 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/01 20:52:35 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_lexer.h"

/*
** This function escapes a character following a backslash
*/

int		escape_char(t_lexer *lexer, char **stack)
{
	*stack = push_char(lexer, *stack);
	if (lexer->input[lexer->pos])
	{
		*stack = push_char(lexer, *stack);
		return (0);
	}
	return (1);
}
