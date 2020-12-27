/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_environment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:48:56 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/27 16:44:34 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft_mem.h"
#include "libft_str.h"
#include "sh_env.h"

/*
** This function duplicates the environment
**
** count: The size of the new environment
**
** returns: The new environment
**          NULL otherwise
*/

char		**dup_environment(size_t count)
{
	char	**result;
	size_t	i;
	size_t	key;

	if (!g_env)
		return (NULL);
	result = ft_calloc((count + 1), sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	key = 0;
	while (i < count)
	{
		if (g_env[i] && ft_strcmp(g_env[i], EMPTY_STR))
		{
			result[key] = ft_strdup(g_env[i]);
			if (!result[key])
				return (NULL);
			key++;
		}
		i++;
	}
	ft_clearenv();
	return (result);
}
