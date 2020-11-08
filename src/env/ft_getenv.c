/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 20:30:15 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/08 22:11:12 by mboivin          ###   ########.fr       */
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
	size_t	i;
	size_t	key_len;

	if (g_env && key)
	{
		i = 0;
		while (g_env && g_env[i])
		{
			if (ft_strcmp(g_env[i], key) == ENVKEY_SEP)
			{
				key_len = ft_strlen(key);
				return ((g_env[i]) + (key_len + 1));
			}
			i++;
		}
	}
	return (NULL);
}
