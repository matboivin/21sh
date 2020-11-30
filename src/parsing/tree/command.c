/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 20:53:42 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/30 19:07:03 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sh_expr.h"

/*
** Complete command
**
** malloc_command()  :  Malloc function
** free_command()    :  Free function
*/

t_cmd		*malloc_command(size_t p_capacity)
{
	t_cmd	*result;

	result = malloc(sizeof(t_cmd));
	if (!result)
		return (NULL);
	result->capacity = p_capacity;
	result->seq_count = 0;
	result->pipe_list = malloc(p_capacity * sizeof(t_pipe_seq *));
	return (result);
}

void		free_command(t_cmd *to_free)
{
	size_t	i;

	if (!to_free)
		return ;
	i = 0;
	if (to_free->pipe_list)
	{
		while (i < to_free->seq_count)
			free_pipe_sequence(to_free->pipe_list[i++]);
		free(to_free->pipe_list);
		to_free->pipe_list = NULL;
	}
	free(to_free);
}
