/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 01:35:35 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/30 18:32:49 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft_str.h"
#include "sh_execution.h"

/*
** This function checks whether the current simple command is a builtin
*/

bool	is_builtin(t_simplecmd *simple_cmd)
{
	return (simple_cmd->builtin_func);
}

/*
** This function checks whether the current simple command is a shell builtin:
** cd, export, env, exit, pwd, unset
*/

bool	is_sh_builtin(t_simplecmd *simple_cmd)
{
	size_t	len;

	len = 0;
	if (is_builtin(simple_cmd))
	{
		if (contain_slash(simple_cmd->cmd_path))
			len = get_cmd_filename(simple_cmd->cmd_path);
		if (ft_strcmp("echo", simple_cmd->cmd_args[CMD_NAME] + len))
			return (true);
	}
	return (false);
}
