/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:18:08 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/01 19:15:21 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "sh_lexer.h"

/*
** This function checks whether the character is a quote
** STRONG QUOTE : '
** WEAK QUOTE : "
*/

static bool	is_quote(int c)
{
	return ((c == STRONG_QUOTE) || (c == WEAK_QUOTE));
}

/*
** This function handles text (no token type found)
** If the character is a quote, it checks the quotes are matching (closed)
** and then adds the characters between quotes to the text stack
** Else, it adds the character to the text stack
**
** returns: 0 on success
**          -1 on error
*/

int			handle_text(t_lexer *lexer, char **stack)
{
	int		ret;

	ret = EXIT_SUCCESS;
	if (is_quote(lexer->input[lexer->pos]))
		ret = handle_quotes(lexer, stack);
	else
		*stack = push_char(lexer, *stack);
	return (ret);
}
