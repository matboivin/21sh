/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 20:14:36 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/14 00:11:53 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "sh_builtins.h"
#include "sh_expansion.h"

/*
** This function searches the command in the list of builtins
*/

static t_builtin_list	g_builtin_list[] =
{
	{ "cd", &cd_builtin },
	{ "echo", &echo_builtin },
	{ "env", &env_builtin },
	{ "exit", &exit_builtin },
	{ "export", &export_builtin },
	{ "pwd", &pwd_builtin },
	{ "unset", &unset_builtin }
};

static void	get_builtin(t_simplecmd *simple_cmd, char *cmd_name)
{
	int		i;

	i = 0;
	while (i < BUILTINS_COUNT)
	{
		if (!ft_strcmp(g_builtin_list[i].name, cmd_name))
		{
			simple_cmd->builtin_func = g_builtin_list[i].func;
			return ;
		}
		i++;
	}
}

void		search_builtin(t_simplecmd *simple_cmd)
{
	size_t	len;

	len = 0;
	if (contain_slash(simple_cmd->cmd_path))
	{
		len = get_cmd_filename(simple_cmd->cmd_path);
		get_builtin(simple_cmd, simple_cmd->cmd_path + len);
	}
	else
		get_builtin(simple_cmd, simple_cmd->cmd_path);
}
