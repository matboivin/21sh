/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 20:30:15 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/09 18:14:12 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "sh_env.h"

/*
** This function returns a string that is the value of the environment variable
** key
**
** key: Name of the variable
**
** returns: If found, the value of the variable
**          NULL otherwise
*/

char		*ft_getenv(char *key)
{
	char	*value;
	int		i;

	if (!g_env || !key)
		return (NULL);
	value = NULL;
	i = find_env(key);
	if (i != FAIL_RET)
	{
		value = g_env[i] + (ft_strlen(key) + 1);
		if (value)
			return (value);
	}
	return (NULL);
}
