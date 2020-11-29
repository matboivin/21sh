/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 20:53:42 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/29 21:34:51 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_str.h"
#include "sh_expr.h"

t_simple_cmd		*malloc_simple_command(void)
{
	t_simple_cmd	*result;

	result = malloc(sizeof(t_simple_cmd));
	if (!result)
		return (NULL);
	result->redir_list = NULL;
	result->input_file = NULL;
	result->output_file = NULL;
	result->arg_count = 0;
	result->cmd_args = NULL;
	return (result);
}

void				free_simple_command(t_simple_cmd *to_free)
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
