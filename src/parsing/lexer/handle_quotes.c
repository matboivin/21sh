/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:17:34 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/12 23:38:17 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "sh_utils.h"
#include "sh_lexer.h"

/*
** If open quotes are closed, returns 0 (success)
*/

static int	close_quote(t_lexer *lexer, char **tok_stack)
{
	return (push_char(lexer, tok_stack));
}

/*
** Else, raises matching error and returns -1
*/

static int	raise_matching_error(char **tok_stack, char quote_type)
{
	ft_strdel(tok_stack);
	handle_matching_error(quote_type);
	return (FAIL_RET);
}

/*
** These functions check if the quotes are matching (closed)
** and then adds the characters between quotes to the text stack
**
** returns: 0 on success
**          -1 on error
*/

static int	handle_quote_type(t_lexer *lexer, char **tok_stack, char quote_type)
{
	push_char(lexer, tok_stack);
	while (lexer->input[lexer->pos] && lexer->input[lexer->pos] != quote_type)
	{
		if ((lexer->input[lexer->pos] == BACKSLASH)
			&& (quote_type == WEAK_QUOTE))
			escape_char(lexer, tok_stack);
		else
			push_char(lexer, tok_stack);
	}
	if (lexer->input[lexer->pos] == quote_type)
		return (close_quote(lexer, tok_stack));
	else
		return (raise_matching_error(tok_stack, quote_type));
}

int			handle_quotes(t_lexer *lexer, char **tok_stack)
{
	if (lexer->input[lexer->pos] == STRONG_QUOTE)
		return (handle_quote_type(lexer, tok_stack, STRONG_QUOTE));
	return (handle_quote_type(lexer, tok_stack, WEAK_QUOTE));
}
