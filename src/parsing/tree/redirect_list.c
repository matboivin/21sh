/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:19:30 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/30 19:03:29 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_str.h"
#include "sh_expr.h"

/*
** Redirection list
**
** malloc_redir_list()  :  Malloc function
** destroy_redir_list() :  Destructor
** free_redir_list()    :  Free function
*/

t_redir_list		*malloc_redir_list(size_t count)
{
	t_redir_list	*result;

	result = malloc(sizeof(t_redir_list));
	if (!result)
		return (NULL);
	result->file_count = 0;
	result->file_list = malloc(count * sizeof(t_io_file *));
	return (result);
}

void				destroy_redir_list(t_redir_list *to_destroy)
{
	size_t			i;

	i = 0;
	if (to_destroy->file_list)
	{
		while (i < to_destroy->file_count)
			free_io_file(to_destroy->file_list[i++]);
	}
}

void				free_redir_list(t_redir_list **to_free)
{
	if (!to_free)
		return ;
	destroy_redir_list(*to_free);
	free(*to_free);
	*to_free = NULL;
}
