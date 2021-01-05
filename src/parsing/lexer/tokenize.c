/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:36:21 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/05 16:54:34 by mboivin          ###   ########.fr       */
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
	char	*stack;
	int		ret;

	token.type = TOKEN_NOT_FOUND;
	stack = NULL;
	ret = EXIT_SUCCESS;
	while (lexer->input[lexer->pos] && !ret)
	{
		token = get_token(lexer->input + lexer->pos);
		if ((lexer->input[lexer->pos] == COMMENT_START) && !stack)
			break ;
		if (lexer->input[lexer->pos] == BACKSLASH)
			ret = escape_char(lexer, &stack);
		else if (token.type)
			handle_token(lexer, token, &stack);
		else
			ret = handle_text(lexer, &stack);
	}
	if (stack && ret != FAIL_RET)
		add_word_to_lexer(lexer, &stack);
	ft_strdel(&stack);
	if (token.type && token.type == TOKEN_PIPE)
		return (lexer->pos == ft_strlen(lexer->input));
	return (ret);
}
