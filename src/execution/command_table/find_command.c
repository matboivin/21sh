/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 20:14:36 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/18 18:25:11 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "libft_str.h"
#include "libft_printf.h"
#include "sh_env.h"
#include "sh_execution.h"

static bool	is_absolute_path(char *cmd_name)
{
	return (ft_strchr(cmd_name, '/') != NULL);
}

static bool	command_found(char **cmd_args, char *path_to_check)
{
	struct stat	statbuf;

	if (lstat(path_to_check, &statbuf) == FAIL_RET)
		return (false);
	// TODO: Check permissions
	cmd_args[CMD_NAME] = ft_strreplace(cmd_args[CMD_NAME], path_to_check);
	ft_strdel(&path_to_check);
	return (true);
}

static void	get_command_path(char **cmd_args)
{
	char	**path_list;
	char	*path_to_check;
	size_t	i;

	path_list = ft_split(ft_getenv("PATH"), PATHS_SEP);
	// TODO: handle empty path
	i = 0;
	while (path_list[i])
	{
		path_to_check = ft_join_n_str(
			3, path_list[i], DIRS_SEP, cmd_args[CMD_NAME]);
		if (command_found(cmd_args, path_to_check))
			break ;
		i++;
		ft_strdel(&path_to_check);
	}
	ft_str_arr_del(path_list);
}

int			find_command(t_simplecmd *simple_cmd)
{
	if (!simple_cmd->argc)
		return (0);
	if (!is_absolute_path(simple_cmd->cmd_args[CMD_NAME]))
		get_command_path(simple_cmd->cmd_args);
	if (simple_cmd->cmd_args[CMD_NAME])
		return (0);
	return (FAIL_RET);
}
