/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_expr.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 21:31:47 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/30 19:07:06 by mboivin          ###   ########.fr       */
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
** IO file
**
** Grammar rule:
** io_file : '<'       WORD
**         | '>'       WORD
**         | '>>'      WORD
**
** type: The token type: LESS ('<'), GREAT ('>') or DGREAT ('>>')
** filename: The filename as a string
*/

typedef struct		s_io_file
{
	t_tok_type		type;
	char			*filename;
}					t_io_file;

/*
** Redirection list
**
** Grammar rule:
** redirect_list :               io_file
**               | redirect_list io_file
**
** file_count: Count of the IO files
** file_list: A list of IO files
*/

typedef struct		s_redir_list
{
	size_t			file_count;
	t_io_file		**file_list;
}					t_redir_list;

/*
** Simple command
**
** Grammar rule:
** simple_command : redirect_list WORD redirect_list
**                | redirect_list WORD
**                | redirect_list
**                |               WORD redirect_list
**                |               WORD
**
** redir_list: List of redirection
** arg_count: Count of the simple command arguments
** cmd_args: Array of simple command arguments
*/

typedef struct		s_simple_cmd
{
	t_redir_list	*redir_list;
	size_t			arg_count;
	char			**cmd_args;
}					t_simple_cmd;

/*
** Pipe sequence
**
** Grammar rule:
** pipe_sequence :                   simple_command
**               | pipe_sequence '|' simple_command
**
** cmd_count: Count of the simple commands
** simple_cmds: Array of simple commands
*/

typedef struct		s_pipe_seq
{
	size_t			cmd_count;
	t_simple_cmd	**simple_cmds;
}					t_pipe_seq;

/*
** Complete command
**
** Grammar rule:
** command :             pipe_sequence
**         | command ';' pipe_sequence
**
** capacity: Maximum capacity of the command list
** seq_count: Count of the pipe sequences
** pipe_list: A list of pipe sequences
*/

typedef struct		s_cmd
{
	size_t			capacity;
	size_t			seq_count;
	t_pipe_seq		**pipe_list;
}					t_cmd;

/*
** IO file
**
** create_io_file()  :  Creator
** malloc_io_file()  :  Malloc function
** free_io_file()    :  Free function
*/

void				create_io_file(
	t_io_file *result, t_tok_type p_type, char *p_filename);
t_io_file			*malloc_io_file(t_tok_type p_type, char *p_filename);
void				free_io_file(t_io_file *to_free);

/*
** Redirection list
**
** malloc_redir_list()  :  Malloc function
** destroy_redir_list() :  Destructor
** free_redir_list()    :  Free function
*/

t_redir_list		*malloc_redir_list(size_t count);
void				destroy_redir_list(t_redir_list *to_destroy);
void				free_redir_list(t_redir_list **to_free);

/*
** Simple command
**
** malloc_simple_command()  :  Malloc function
** free_simple_command()    :  Free function
*/

t_simple_cmd		*malloc_simple_command(void);
void				free_simple_command(t_simple_cmd *to_free);

/*
** Pipe sequence
**
** malloc_pipe_sequence()  :  Malloc function
** free_pipe_sequence()    :  Free function
*/

t_pipe_seq			*malloc_pipe_sequence(size_t count);
void				free_pipe_sequence(t_pipe_seq *to_free);

/*
** Complete command
**
** malloc_command()  :  Malloc function
** free_command()    :  Free function
*/

t_cmd				*malloc_command(size_t p_capacity);
void				free_command(t_cmd *to_free);

#endif
