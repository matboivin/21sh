/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 20:30:15 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/09 16:04:00 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft_str.h"
#include "sh_env.h"

/*
** This function returns a string that is the value of the environment variable
** key
**
** returns: If found, the value of the variable
**          NULL otherwise
*/

char		*ft_getenv(char *key)
{
	char	*value;
	size_t	i;

	if (!g_env || !key)
		return (NULL);
	value = NULL;
	i = 0;
	while (g_env && g_env[i])
	{
		if (ft_strcmp(g_env[i], key) == ENVKEY_SEP)
		{
			value = g_env[i] + (ft_strlen(key) + 1);
			if (value)
				return (value);
		}
		i++;
	}
	return (NULL);
}
