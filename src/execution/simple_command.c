/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 16:49:13 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/11 16:55:37 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "sh_execution.h"

/*
** Simple command
**
** malloc_simple_cmd()  :  Malloc function
** free_simple_cmd()    :  Free function
** print_simple_cmd()   :  Debug
*/

t_simplecmd		*malloc_simple_cmd(void)
{
	t_simplecmd	*result;

	result = malloc(sizeof(t_simplecmd));
	if (!result)
		return (NULL);
	result->argc = 0;
	result->cmd_args = NULL;
	result->input_file = NULL;
	result->output_file = NULL;
	return (result);
}

void			free_simple_cmd(t_simplecmd *to_free)
{
	if (!to_free)
		return ;
	if (to_free->cmd_args)
	{
		ft_str_arr_del(to_free->cmd_args);
		to_free->cmd_args = NULL;
	}
	if (to_free->input_file)
		to_free->input_file = NULL;
	if (to_free->output_file)
		to_free->output_file = NULL;
	free(to_free);
}

void			print_simple_cmd(t_simplecmd *simple_cmd)
{
	size_t		i;

	if (!simple_cmd || !simple_cmd->cmd_args)
		return ;
	i = 0;
	while (i < simple_cmd->argc)
		ft_printf(" %s", simple_cmd->cmd_args[i++]);
}
