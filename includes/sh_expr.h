/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_expr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 21:31:47 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/30 18:17:35 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_EXPR_H
# define SH_EXPR_H

# include "sh_define.h"
# include "sh_parser.h"

/*
** One struct per expression
** Refer to the Grammar
*/

/*
** io_file : '<'       filename
**         | '>'       filename
**         | '>>'      filename
**
** type: The token type: LESS ('<'), GREAT ('>') or DGREAT ('>>')
** filename: The filename as string
*/

typedef struct		s_io_file
{
	t_tok_type		type;
	char			*filename;
}					t_io_file;

/*
** redirect_list :               io_file
**               | redirect_list io_file
**
** io_files: An array of IO files
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
**
** redir_list: List of redirection
** arg_count: Number of the simple command arguments
** cmd_args: Array of simple command arguments
*/

typedef struct		s_simple_cmd
{
	t_redirect_list	*redir_list;
	size_t			arg_count;
	char			**cmd_args;
}					t_simple_cmd;

/*
** pipe_sequence :                   simple_command
**               | pipe_sequence '|' simple_command
**
** cmd_count: Number of simple commands
** simple_cmds: Array of simple commands
*/

typedef struct		s_pipe_seq
{
	size_t			cmd_count;
	t_simple_cmd	**simple_cmds;
}					t_pipe_seq;

/*
** command :             pipe_sequence
**         | command ';' pipe_sequence
**
** capacity: Maximum capacity of the command list
** seq_count: Number of pipe sequences
** pipe_seq: Array of pipe sequences
*/

typedef struct		s_cmd
{
	size_t			capacity;
	size_t			seq_count;
	t_pipe_seq		**pipe_seq;
}					t_cmd;

t_simple_cmd		*malloc_simple_command(void);
void				free_simple_command(t_simple_cmd *to_free);

t_pipe_seq			*malloc_pipe_sequence(size_t p_capacity);
void				free_pipe_sequence(t_pipe_seq *to_free);

t_cmd				*malloc_command(size_t p_capacity);
void				free_command(t_cmd *to_free);

#endif
