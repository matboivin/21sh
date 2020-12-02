/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:34:28 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/02 18:40:17 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_PARSER_H
# define SH_PARSER_H

# include <stdbool.h>
# include "sh_define.h"
# include "sh_lexer.h"
# include "sh_ast.h"
# include "sh_expr.h"

/*
** Checks whether the token type is the one expected
*/

bool	is_expected_type(t_tok_type current, t_tok_type expected);

/*
** Processes the tokens into an Abstract Syntax Tree (AST)
*/

bool	parse(t_ast_node **ast, t_lexer *lexer, size_t *pos);

/*
** Parses a Word
*/

bool	parse_word(t_ast_node **ast, t_lexer *lexer, size_t *pos);

/*
** Parses an IO file
*/

bool	parse_io_file(t_ast_node **ast, t_lexer *lexer, size_t *pos);

#endif
