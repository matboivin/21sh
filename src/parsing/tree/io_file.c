/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 18:19:20 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/30 19:04:28 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sh_expr.h"

/*
** IO file
**
** create_io_file()  :  Creator
** malloc_io_file()  :  Malloc function
** free_io_file()    :  Free function
*/

void			create_io_file(
	t_io_file *result, t_tok_type p_type, char *p_filename)
{
	result->type = p_type;
	result->filename = p_filename;
}

t_io_file		*malloc_io_file(t_tok_type p_type, char *p_filename)
{
	t_io_file	*result;

	result = malloc(sizeof(t_io_file));
	if (!result)
		return (NULL);
	create_io_file(result, p_type, p_filename);
	return (result);
}

void			free_io_file(t_io_file *to_free)
{
	if (!to_free)
		return ;
	free(to_free);
	to_free = NULL;
}
