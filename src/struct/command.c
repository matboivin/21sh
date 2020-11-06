/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 16:36:23 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/06 17:31:49 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_str.h"
#include "libft_printf.h"
#include "ft_command.h"

t_cmd		*malloc_cmd_table(size_t p_capacity)
{
	t_cmd	*result;

	result = malloc(sizeof(t_cmd));
	if (!result)
		return (NULL);
	result->capacity = p_capacity;
	result->cmd_count = 0;
	result->simple_cmds = malloc(p_capacity * sizeof(t_simplecmd *));
	result->input_file = NULL;
	result->output_file = NULL;
	return (result);
}

void		free_cmd_table(t_cmd *to_free)
{
	size_t	i;

	if (!to_free)
		return ;
	i = 0;
	if (to_free->simple_cmds)
	{
		while (i < to_free->capacity)
			free_command(to_free->simple_cmds[i++]);
		free(to_free->simple_cmds);
		to_free->simple_cmds = NULL;
	}
	if (to_free->input_file)
		to_free->input_file = NULL;
	if (to_free->output_file)
		to_free->output_file = NULL;
	free(to_free);
}

void		print_cmd_table(t_cmd *cmds)
{
	size_t	i;

	if (!cmds)
		return ;
	if (cmds->cmd_count == 0)
	{
		ft_printf("Command table is empty\n");
		return ;
	}
	i = 0;
	ft_printf("\nCommand table:\n");
	while (i < cmds->cmd_count)
	{
		ft_printf("[%ld]", i);
		print_command_args(cmds->simple_cmds[i++]);
		ft_printf("\n");
	}
}
