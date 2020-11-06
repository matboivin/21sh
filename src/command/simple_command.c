/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 16:36:23 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/06 18:52:56 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_str.h"
#include "libft_printf.h"
#include "ft_define.h"
#include "command.h"

t_simplecmd		*malloc_simple_command(void)
{
	t_simplecmd	*result;

	result = malloc(sizeof(t_simplecmd));
	if (!result)
		return (NULL);
	result->argc = 0;
	result->cmd_args = NULL;
	return (result);
}

void			get_command_args(t_simplecmd *simple_cmd, char *args)
{
	simple_cmd->cmd_args = ft_split(args, ARGS_SEP);
	simple_cmd->argc = ft_str_arr_len(simple_cmd->cmd_args);
}

void			free_command(t_simplecmd *to_free)
{
	if (!to_free)
		return ;
	if (to_free->cmd_args)
	{
		ft_str_arr_del(to_free->cmd_args);
		to_free->cmd_args = NULL;
	}
	free(to_free);
}

void			print_command_args(t_simplecmd *simple_cmd)
{
	size_t		i;

	if (!simple_cmd || !simple_cmd->cmd_args)
		return ;
	i = 0;
	while (i < simple_cmd->argc)
		ft_printf(" %s", simple_cmd->cmd_args[i++]);
}
