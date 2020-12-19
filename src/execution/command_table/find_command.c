/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 20:14:36 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/19 20:45:26 by mboivin          ###   ########.fr       */
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

static bool		is_path(char *cmd_path)
{
	return (ft_strchr(cmd_path, '/') != NULL);
}

static bool		command_found(char **cmd_path, char *path_to_check)
{
	bool		ret_val;
	struct stat	statbuf;

	ret_val = false;
	// TODO: Check permissions
	if (lstat(path_to_check, &statbuf) != FAIL_RET)
	{
		ret_val = true;
		*cmd_path = ft_strreplace(*cmd_path, path_to_check);
	}
	ft_strdel(&path_to_check);
	return (ret_val);
}

static void		get_command_path(char **cmd_path)
{
	char		**path_list;
	char		*path_to_check;
	size_t		i;

	path_list = ft_split(ft_getenv("PATH"), PATHS_SEP);
	// TODO: handle empty path
	i = 0;
	while (path_list[i])
	{
		path_to_check = ft_join_n_str(3, path_list[i], DIRS_SEP, *cmd_path);
		if (command_found(cmd_path, path_to_check))
		{
			ft_str_arr_del(path_list);
			return ;
		}
		i++;
	}
	ft_str_arr_del(path_list);
	handle_cmd_not_found(*cmd_path);
}

// TODO: search in the list of builtins

int				find_command(t_simplecmd *simple_cmd)
{
	if (!simple_cmd->argc)
		return (0);
	if (!is_path(simple_cmd->cmd_path))
		get_command_path(&(simple_cmd->cmd_path));
	if (simple_cmd->cmd_path)
		return (0);
	return (FAIL_RET);
}
