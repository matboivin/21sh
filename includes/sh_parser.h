/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:34:28 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/03 16:59:21 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_PARSER_H
# define SH_PARSER_H

# include <stdbool.h>
# include "sh_define.h"
# include "sh_lexer.h"
# include "sh_ast.h"

/*
** Checks whether the token type is the one expected
*/

bool	is_expected_type(t_tok_type current, t_tok_type expected);

/*
** Processes the tokens into an Abstract Syntax Tree (AST)
*/

int		parse(t_ast_node **ast, t_lexer *lexer);

/*
** Parses a Word
*/

bool	parse_word(t_ast_node **ast, t_lexer *lexer, size_t *pos);

/*
** Parses an IO file
*/

bool	parse_io_file(t_ast_node **ast, t_lexer *lexer, size_t *pos);

/*
** Parses a command suffix
*/

bool	parse_cmd_suffix(t_ast_node **ast, t_lexer *lexer, size_t *pos);

/*
** Parses a simple command
*/

bool	parse_simple_cmd(t_ast_node **ast, t_lexer *lexer, size_t *pos);

/*
** Parses a pipe sequence
*/

bool	parse_pipe_sequence(t_ast_node **ast, t_lexer *lexer, size_t *pos);

/*
** Parses a command
*/

bool	parse_command(t_ast_node **ast, t_lexer *lexer, size_t *pos);

#endif
