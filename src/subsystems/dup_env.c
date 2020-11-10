/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 12:48:56 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/10 13:54:32 by mboivin          ###   ########.fr       */
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

char		**dup_env(size_t count)
{
	char	**result;
	size_t	i;

	if (!g_env)
		return (NULL);
	result = ft_calloc((count + 1), sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (g_env && g_env[i] && i < count)
	{
		if (ft_strcmp(g_env[i], EMPTY_STR))
		{
			result[i] = ft_strdup(g_env[i]);
			if (!result[i])
				return (NULL);
		}
		i++;
	}
	ft_clearenv();
	return (result);
}
