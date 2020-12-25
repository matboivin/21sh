/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_define.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:52:37 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/26 00:37:37 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_DEFINE_H
# define SH_DEFINE_H
# include <signal.h>
# include "libft_define.h"

# define SHELL_NAME "minishell"

/*
** PS1: environment variable which contains the value of the default prompt.
** It changes the shell command prompt appearance and environment.
*/

# define PS1 "\033[34m┌─[\033[0mminishell\033[34m]\n└──╼\033[0m "

/*
** PS2: environment variable which contains the value the prompt used for a
** command continuation interpretation. You see it when you write a long
** command in many lines.
*/

# define PS2 "> "

# define NO_ARGS 1
# define FIRST_PARAM 1
# define DEFAULT_VALUE 0
# define FAIL_RET -1
# define MAX_STATES 256

/*
** Lexer
*/

# define DEFAULT_CAPACITY 42
# define MAX_TOKENS 12

/*
** Parsing
*/

# define COMMENT_START '#'
# define BACKSLASH '\\'
# define STRONG_QUOTE '\''
# define WEAK_QUOTE '\"'
# define DOLLAR_SIGN '$'
# define ENVKEY_SEP '='
# define PATHS_SEP ':'
# define DIRS_SEP "/"

/*
** Execution, pipes and files
*/

# define BUILTINS_COUNT 7
# define REDIR_INPUT "<"
# define REDIR_OUTPUT ">"
# define REDIR_APPEND_OUTPUT ">>"
# define NO_FILE -1
# define CMD_NAME 0
# define READ_END 0
# define WRITE_END 1
# define FILE_PERMISSIONS 0644

/*
** Exit codes
*/

/*
** Misuse of shell builtins
*/

# define INCORRECT_USAGE 2

/*
** Command itself failed (timeout disabled)
*/

# define TIMEOUT_FAIL 125

/*
** Command invoked cannot execute
*/

# define NOT_EXECUTABLE 126

/*
** "command not found"
*/

# define CMD_NO_FOUND 127

/*
** The return value of a command is its exit status, or 128 + N if the command
** is terminated by signal N
*/

# define FATAL_ERROR 128

/*
** Exit status out of range
*/

# define MAX_EXIT_VALUE 255

/*
** Exit status
*/

extern volatile sig_atomic_t	g_status;

/*
** Flags
*/

extern volatile sig_atomic_t	g_done;

/*
** Environment
*/

extern char	**g_env;

#endif
