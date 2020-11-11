/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_define.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:52:37 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/11 14:29:58 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_DEFINE_H
# define SH_DEFINE_H
# include "libft_define.h"
# include <signal.h>

# define SHELL_PROMPT "ft_sh > "
# define DEFAULT_ARGC 1

# define FAIL_RET -1

/*
** Parsing
*/

# define ARGS_SEP ' '
# define ENVKEY_SEP '='
# define PATHS_SEP ':'
# define DIRS_SEP "/"

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
