/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 20:14:36 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/16 20:36:46 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft_str.h"
#include "sh_execution.h"

static bool	is_absolute_path(char *cmd_name)
{
	return (ft_strchr(cmd_name, '/') != NULL);
}

static bool	command_found(char **cmd_args, char *path_to_check)
{
	t_stat	statbuf;

	if (lstat(path_to_check, &statbuf) == FAIL_RET)
		return (false);
	ft_strdel(&(cmd_args[CMD_NAME]));
	cmd_args[CMD_NAME] = ft_strdup(path_to_check);
	ft_strdel(&path_to_check);
	return (true);
}

static void	get_command_path(char **cmd_args)
{
	char	**path_list;
	char	*path_to_check;
	size_t	i;

	path_list = ft_split(ft_getenv("PATH"), PATHS_SEP);
	i = 0;
	while (path_list[i])
	{
		path_to_check = ft_join_n_str(
			path_list[i], DIRS_SEP, cmd_args[CMD_NAME]);
		if (command_found(cmd_args, path_to_check))
			break ;
		i++;
		ft_strdel(&path_to_check);
	}
	ft_str_arr_del(path_list);
}

void		find_command(t_simplecmd *simple_cmd)
{
	if (!is_absolute_path(simple_cmd->cmd_args[CMD_NAME]))
		get_command_path(simple_cmd->cmd_args);
}
