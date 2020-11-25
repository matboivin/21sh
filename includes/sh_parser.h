/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:34:28 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/25 14:42:07 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_PARSER_H
# define SH_PARSER_H

# include "sh_define.h"
# include "sh_lexer.h"
# include "sh_ast.h"

/*
** Processes the tokens according to the grammar and builds the AST
*/

void	parse(t_ast_node **parser, t_lexer *lexer);

#endif
