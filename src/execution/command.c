/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 16:49:05 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/15 16:09:26 by mboivin          ###   ########.fr       */
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
	t_cmd	*result;

	result = malloc(sizeof(t_cmd));
	if (!result)
	{
		g_status = EXIT_FAILURE;
		return (NULL);
	}
	result->capacity = p_capacity;
	result->cmd_count = DEFAULT_VALUE;
	//result->simple_cmds = malloc(p_capacity * sizeof(t_simplecmd *));
	result->simple_cmds = NULL;
	return (result);
}

void		destroy_cmd(t_cmd to_destroy)
{
	size_t	i;

	i = 0;
	if (to_destroy.simple_cmds)
	{
		while (i < to_destroy.capacity)
			free_simple_cmd(to_destroy.simple_cmds[i++]);
		free(to_destroy.simple_cmds);
		to_destroy.simple_cmds = NULL;
	}
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

void		print_cmd(t_cmd *cmds)
{
	size_t	i;

	if (!cmds)
		return ;
	if (cmds->cmd_count == DEFAULT_VALUE)
	{
		ft_printf("Command table is empty\n");
		return ;
	}
	i = 0;
	ft_printf("\nCommand table:\n");
	while (i < cmds->cmd_count)
	{
		ft_printf("[%ld]", i);
		print_simple_cmd(cmds->simple_cmds[i++]);
		ft_printf("\n");
	}
}
