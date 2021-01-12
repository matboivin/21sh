/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:18:08 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/12 23:38:49 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "sh_subsystems.h"
#include "sh_lexer.h"

/*
** This function handles text (no token type found)
** If the character is a quote, it checks the quotes are matching (closed)
** and then adds the characters between quotes to the text stack
** Else, it adds the character to the text stack
**
** returns: 0 on success
**          -1 on error
*/

int		handle_text(t_lexer *lexer, char **tok_stack)
{
	int	ret;

	ret = EXIT_SUCCESS;
	if (is_quote(lexer->input[lexer->pos]))
		ret = handle_quotes(lexer, tok_stack);
	else
		push_char(lexer, tok_stack);
	return (ret);
}
