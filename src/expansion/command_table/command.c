/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 16:49:05 by mboivin           #+#    #+#             */
/*   Updated: 2021/04/15 19:00:37 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "sh_command.h"

/*
** Command
**
** malloc_cmd()   :  Malloc function
** destroy_cmd()  :  Destructor
** free_cmd()     :  Free function
** print_cmd()    :  Debug
*/

t_cmd		*malloc_cmd(size_t p_capacity)
{
	t_cmd	*result = NULL;

	result = malloc(sizeof(t_cmd));
	if (!result)
	{
		g_status = EXIT_FAILURE;
		return (NULL);
	}
	result->capacity = p_capacity;
	result->curr_cmd = DEFAULT_VALUE;
	result->cmd_count = DEFAULT_VALUE;
	result->simple_cmds = malloc(p_capacity * sizeof(t_simplecmd *));
	return (result);
}

void		destroy_cmd(t_cmd to_destroy)
{
	size_t	i;

	i = 0;
	if (to_destroy.cmd_count)
	{
		while (i < to_destroy.cmd_count)
			free_simple_cmd(to_destroy.simple_cmds[i++]);
	}
	free(to_destroy.simple_cmds);
	to_destroy.simple_cmds = NULL;
}

void		free_cmd(t_cmd **to_free)
{
	if (to_free)
	{
		destroy_cmd(**to_free);
		free(*to_free);
		*to_free = NULL;
	}
}

void		print_cmd(t_cmd *cmd)
{
	size_t	i;

	if (!cmd)
		return ;
	ft_printf("\n----------- DEBUG: COMMAND TABLE ---\n");
	if (cmd->cmd_count == DEFAULT_VALUE)
	{
		ft_printf("Command table is empty\n");
		return ;
	}
	ft_printf(
			"commands: %ld\ncapacity: %ld\n",
			cmd->cmd_count, cmd->capacity);
	i = 0;
	while (i < cmd->cmd_count)
	{
		ft_printf("  [%ld]\t", i);
		print_simple_cmd(cmd->simple_cmds[i++]);
		ft_printf("\n");
	}
	ft_printf("------------------------------------\n");
}
