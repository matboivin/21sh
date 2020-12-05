/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_define.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:52:37 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/05 18:25:18 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_DEFINE_H
# define SH_DEFINE_H
# include <signal.h>
# include "libft_define.h"

# define SHELL_NAME "ft_sh"
# define SHELL_PROMPT "ft_sh > "
# define LINE_PROMPT "> "
# define DEFAULT_ARGC 1
# define FAIL_RET -1

/*
** Lexer
*/

# define DEFAULT_CAPACITY 42
# define MAX_TOKENS 15

/*
** Parsing
*/

# define COMMENT_START '#'
# define BACKSLASH '\\'
# define STRONG_QUOTE '\''
# define WEAK_QUOTE '\"'
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
