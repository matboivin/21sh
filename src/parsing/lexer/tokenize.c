/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:36:21 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/12 23:35:47 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_str.h"
#include "sh_lexer.h"

/*
** This function splits the input string into tokens
**
** returns: 0 on success
**          1 if the input is not finished
**          -1 on error
*/

int			tokenize(t_lexer *lexer)
{
	t_regex	token;
	char	*tok_stack;
	int		ret;

	token.type = TOKEN_NOT_FOUND;
	tok_stack = NULL;
	ret = EXIT_SUCCESS;
	while (lexer->input[lexer->pos] && !ret)
	{
		token = get_token(lexer->input + lexer->pos);
		if ((lexer->input[lexer->pos] == COMMENT_START) && !tok_stack)
			break ;
		if (lexer->input[lexer->pos] == BACKSLASH)
			ret = escape_char(lexer, &tok_stack);
		else if (token.type)
			handle_token(lexer, token, &tok_stack);
		else
			ret = handle_text(lexer, &tok_stack);
	}
	if (tok_stack && ret != FAIL_RET)
		add_word_to_lexer(lexer, &tok_stack);
	ft_strdel(&tok_stack);
	if (token.type && token.type == TOKEN_PIPE)
		return (lexer->pos == ft_strlen(lexer->input));
	return (ret);
}
