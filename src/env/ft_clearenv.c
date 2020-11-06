/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clearenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 19:45:58 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/06 19:52:38 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "sh_env.h"
#include "ft_sh.h"

/*
** This function removes all entries from the environment
**
** returns: 0 on success
**          A non-zero value otherwise
*/

int			ft_clearenv(void)
{
	t_env	*cursor;
	t_env	*next_key;

	if (!g_env)
		return (-1);
	cursor = g_env;
	while (cursor)
	{
		next_key = cursor->next;
		free(cursor);
		cursor = next_key;
	}
	g_env = NULL;
	return (0);
}
