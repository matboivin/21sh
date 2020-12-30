/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 20:14:36 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/30 21:04:45 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "libft_str.h"
#include "sh_env.h"
#include "sh_utils.h"
#include "sh_execution.h"

static bool		command_found(char **cmd_path, char *path_to_check)
{
	bool		ret;
	struct stat	statbuf;

	ret = false;
	// TODO: Check permissions
	if (lstat(path_to_check, &statbuf) != FAIL_RET)
	{
		ret = true;
		*cmd_path = ft_strreplace(*cmd_path, path_to_check);
	}
	ft_strdel(&path_to_check);
	return (ret);
}

static char		*get_path_value(void)
{
	char		*result;

	result = NULL;
	result = ft_getenv("PATH");
	if (!ft_getenv("PATH"))
	{
		if (!ft_getenv("PWD"))
			set_working_dir();
		result = ft_getenv("PWD");
	}
	return (result);
}

static int		search_executable(char **cmd_path)
{
	char		**path_list;
	char		*path_to_check;
	size_t		i;

	i = 0;
	path_list = ft_split(get_path_value(), PATHS_SEP);
	if (!path_list)
		return (FAIL_RET);
	while (path_list[i])
	{
		path_to_check = ft_join_n_str(3, path_list[i], DIRS_SEP, *cmd_path);
		if (command_found(cmd_path, path_to_check))
		{
			ft_str_arr_del(path_list);
			return (0);
		}
		i++;
	}
	ft_str_arr_del(path_list);
	handle_cmd_not_found(*cmd_path);
	return (FAIL_RET);
}

/*
** This function searches the command to run
*/

int				search_command(t_simplecmd *simple_cmd)
{
	int			ret;

	ret = 0;
	if (!simple_cmd->argc)
		return (FAIL_RET);
	search_builtin(simple_cmd);
	if (!simple_cmd->builtin_func && !contain_slash(simple_cmd->cmd_path))
		ret = search_executable(&(simple_cmd->cmd_path));
	if (simple_cmd->cmd_path && ret != FAIL_RET)
		return (0);
	return (FAIL_RET);
}
