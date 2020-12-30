/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_simple_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 17:46:26 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/30 20:52:43 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include "libft_str.h"
#include "sh_execution.h"

/*
** This function adds a simple command to the command table
*/

static void			check_char_devices(int argc, char **argv)
{
	int				i;
	size_t			len;

	i = FIRST_PARAM;
	len = 0;
	if (argc == NO_ARGS)
		return ;
	len = get_cmd_filename(argv[CMD_NAME]);
	if (ft_strcmp(argv[CMD_NAME] + len, "cat"))
		return ;
	while (i < argc)
	{
		if ((!ft_strcmp(argv[i], "/dev/random"))
			|| (!ft_strcmp(argv[i], "/dev/zero")))
			g_char_dev = true;
		i++;
	}
}

static t_simplecmd	*get_simple_cmd(t_ast_node *node)
{
	t_simplecmd		*result;
	int				ret;

	ret = 0;
	result = malloc_simple_cmd();
	if (!result)
		return (NULL);
	get_cmd_arg_count(result, node);
	get_cmd_args(result, node);
	ret = get_files(result, node);
	if (ret != FAIL_RET)
	{
		ret = search_command(result);
		if (ret != FAIL_RET)
		{
			check_char_devices(result->argc, result->cmd_args);
			return (result);
		}
	}
	free_simple_cmd(result);
	return (NULL);
}

void				add_simple_cmd(t_cmd *cmd, t_ast_node *node)
{
	cmd->simple_cmds[cmd->cmd_count] = get_simple_cmd(node);
	if (cmd->simple_cmds[cmd->cmd_count])
		cmd->cmd_count += 1;
}
