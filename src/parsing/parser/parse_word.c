/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 19:58:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/06 19:57:01 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include "libft_printf.h"
#include "libft_ctype.h"
#include "libft_str.h"
#include "sh_env.h"
#include "sh_parser.h"

/*
** This function parses a Word
**
** returns: true if the node creation succeeded
**          false otherwise
*/

static void		substitute_var(char **data)
{
	char		*result;
	char		*dollar_sign;
	size_t		start;
	size_t		len;

	if (**data == STRONG_QUOTE)
		return ;
	result = NULL;
	dollar_sign = NULL;
	len = 0;
	if ((dollar_sign = ft_strchr(*data, '$')))
	{
		dollar_sign++;
		start = dollar_sign - *data;
		while (ft_isalnum(dollar_sign[len]) || dollar_sign[len] == '_')
			len++;
		result = ft_getenv(ft_substr(*data, start, len));
		ft_printf("%s\n", result);
	}
}

bool			parse_word(t_ast_node **ast, t_lexer *lexer)
{
	t_ast_node	*word_node;

	word_node = malloc_ast_node(NODE_WORD, lexer->tokens[lexer->pos]->value);
	substitute_var(&(word_node->data));
	if (eat(lexer, TOKEN_WORD) && word_node)
	{
		append_node_left(ast, word_node);
		return (true);
	}
	free_ast(&word_node);
	return (false);
}
