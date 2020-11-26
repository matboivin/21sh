/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_expr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 21:31:47 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/26 16:15:33 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_EXPR_H
# define SH_EXPR_H

# include "sh_define.h"
# include "sh_parser.h"

/*
** io_redirect : '<'       filename
**             | '>'       filename
**             | DGREAT    filename
*/

typedef struct		s_io_redir
{
	t_tok_type		op;
	char		*	filename;
}					t_io_redir;

/*
** cmd_prefix : io_redirect
**            | cmd_prefix io_redirect
*/

typedef struct		s_cmd_prefix
{
	t_io_redir		**io_redirect;
}					t_cmd_prefix;

/*
** cmd_suffix : io_redirect
**            | cmd_suffix io_redirect
*/

typedef struct		s_cmd_suffix
{
	t_io_redir		**io_redirect;
	char			**words;
}					t_cmd_suffix;

/*
** simple_command : cmd_prefix cmd_word cmd_suffix
**                | cmd_prefix cmd_word
**                | cmd_prefix
**                | cmd_name cmd_suffix
**                | cmd_name
*/

typedef struct		s_simple_cmd
{
	t_cmd_prefix	prefix;
	char			*cmd;
	t_cmd_suffix	suffix;
}					t_simple_cmd;

/*
** pipe_sequence :                   simple_command
**               | pipe_sequence '|' simple_command
*/

typedef struct		s_pipe_seq
{
	t_simple_cmd	**simple_cmd;
}					t_pipe_seq;

/*
** and_or :               pipe_sequence
**        | and_or AND_IF pipe_sequence
**        | and_or OR_IF  pipe_sequence
*/

typedef struct		s_and_or
{
	t_pipe_seq		*pipe_seq;
	t_tok_type		op;
	struct s_and_or	*next;
}					t_and_or;

#endif
