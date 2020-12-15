/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 16:49:13 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/15 22:01:15 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "sh_command.h"

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
	{
		g_status = EXIT_FAILURE;
		return (NULL);
	}
	result->argc = DEFAULT_VALUE;
	result->cmd_args = NULL;
	result->in_fd = -1;
	result->out_fd = -1;
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
	free(to_free);
}

void			print_simple_cmd(t_simplecmd *simple_cmd)
{
	size_t		i;

	if (!simple_cmd || !simple_cmd->cmd_args)
		return ;
	i = 0;
	ft_printf("argc: %d\t", simple_cmd->argc);
	while (i < simple_cmd->argc)
		ft_printf("|%s| ", simple_cmd->cmd_args[i++]);
}
