/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_define.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:52:37 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/12 11:34:31 by ouram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_DEFINE_H
# define SH_DEFINE_H
# include <signal.h>
# include "libft_define.h"

# define DEFAULT_SHELL_NAME "minishell"

/*
** PS1: environment variable which contains the value of the default prompt.
** It changes the shell command prompt appearance and environment.
*/

# define OP_PROMPT "\033[34m┌─[\033[0m"
# define END_PROMPT "\033[34m]\n└──╼\033[0m "

/*
** PS2: environment variable which contains the value the prompt used for a
** command continuation interpretation. You see it when you write a long
** command in many lines.
*/

# define FT_PS2 "> "

# define DEFAULT_ARGC 1
# define FAIL_RET -1

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

/*
** Execution, pipes and files
*/

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
