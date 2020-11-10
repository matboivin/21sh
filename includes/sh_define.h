/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_define.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 16:52:37 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/10 15:39:48 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_DEFINE_H
# define SH_DEFINE_H
# include "libft_define.h"

# define SHELL_PROMPT "ft_sh > "
# define DEFAULT_ARGC 1

# define FAIL_RET -1

/*
** Parsing
*/

# define CMD_NAME 0
# define ARGS_SEP ' '
# define ENVKEY_SEP '='
# define PATHS_SEP ':'
# define DIRS_SEP "/"
# define SLASH_C '/'

/*
** Pipes and files
*/

# define READ_END 0
# define WRITE_END 1
# define FILE_PERMISSIONS 0644

/*
** Environment
*/

extern char	**g_env;

#endif
