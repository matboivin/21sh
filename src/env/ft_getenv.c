/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 20:30:15 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/06 17:46:22 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft_str.h"
#include "ft_define.h"
#include "ft_env.h"

/*
** This function returns a string that is the value of the environment variable
** key. If the environment variable key is not defined, the value is a null
** pointer.
*/

char		*ft_getenv(char **environ, const char *key)
{
	size_t	key_len;

	if (environ && key)
	{
		key_len = ft_strlen(key);
		while (*environ)
		{
			if (!ft_strncmp(*environ, key, key_len))
			{
				(*environ) += key_len;
				if (!ft_strncmp(*environ, ENVKEY_SEP, 1))
					return ((*environ) + 1);
			}
			environ++;
		}
	}
	return (NULL);
}
