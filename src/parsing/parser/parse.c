/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 18:29:41 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/03 18:42:50 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include "libft_printf.h"
#include "sh_utils.h"
#include "sh_parser.h"

/*
** This function processes the tokens into an Abstract Syntax Tree (AST)
**
** ast: The AST to complete
** lexer: The lexer containing the tokens
** pos: The position in the lexer
*/

int		parse(t_ast_node **ast, t_lexer *lexer)
{
	size_t	parsed_tokens;
	bool	ret_val;

	parsed_tokens = 0;
	ret_val = true;
	while ((parsed_tokens < lexer->size) && ret_val)
	{
		ret_val = parse_pipe_sequence(ast, lexer, &parsed_tokens);
		//ret_val = parse_simple_cmd(ast, lexer, &parsed_tokens);
		//ret_val = parse_cmd_suffix(ast, lexer, &parsed_tokens);
		//ret_val = parse_io_file(ast, lexer, &parsed_tokens);
	}
	// TODO: Syntax fixing
	if (parsed_tokens != lexer->size)
	{
		ft_dprintf(STDERR_FILENO, "Parsing error\n");
		return (FAIL_RET);
	}
	return (0);
}
