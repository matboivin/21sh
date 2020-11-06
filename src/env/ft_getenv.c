/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 20:30:15 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/06 19:44:06 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft_str.h"
#include "ft_define.h"
#include "sh_env.h"

/*
** This function returns a string that is the value of the environment variable
** key. If the environment variable key is not defined, the value is a null
** pointer.
*/

char		*ft_getenv(const char *key)
{
	t_env	*cursor;

	if (g_env && key)
	{
		cursor = g_env;
		while (cursor)
		{
			if (!ft_strcmp(cursor->key, key))
				return (cursor->value);
			cursor = cursor->next;
		}
	}
	return (NULL);
}
