/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_expr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 21:31:47 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/29 20:30:23 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_EXPR_H
# define SH_EXPR_H

# include "sh_define.h"
# include "sh_parser.h"

/*
** One struct per expression (see the Grammar)
*/

/*
** io_file : '<'       filename
**         | '>'       filename
**         | DGREAT    filename
*/

typedef struct		s_io_file
{
	t_tok_type		op;
	char			*filename;
}					t_io_file;

/*
** redirect_list :               io_file
**               | redirect_list io_file
*/

typedef struct		s_redirect_list
{
	t_io_file		**io_files;
}					t_redirect_list;

/*
** simple_command : redirect_list WORD redirect_list
**                | redirect_list WORD
**                | redirect_list
**                |               WORD redirect_list
**                |               WORD
*/

typedef struct		s_simple_cmd
{
	t_redirect_list	redir_list;
	char			*input_file;
	char			*output_file;
	size_t			arg_count;
	char			**cmd_args;
}					t_simple_cmd;

/*
** pipe_sequence :                   simple_command
**               | pipe_sequence '|' simple_command
*/

typedef struct		s_pipe_seq
{
	size_t			seq_count;
	t_simple_cmd	**simple_cmd;
}					t_pipe_seq;

/*
** command :             pipe_sequence
**         | command ';' pipe_sequence
*/

typedef struct		s_cmd
{
	size_t			capacity;
	size_t			cmd_count;
	t_pipe_seq		**pipe_seq;
}					t_cmd;

#endif
