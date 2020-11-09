/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:56:56 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/09 18:17:38 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft_mem.h"
#include "libft_str.h"
#include "sh_define.h"
#include "sh_env.h"
#include "ft_sh.h"

/*
** This function appends a new definition to the environment
**
** s: The entry to add
**
** returns: The new environment
**          NULL otherwise
*/

char		**ft_putenv(char *s)
{
	size_t	i;
	size_t	count;
	char	**new_env;

	if (!s)
		return (NULL);
	count = ft_str_arr_len(g_env);
	new_env = ft_calloc((count + 2), sizeof(char *));
	if (!new_env)
		exit_error();
	i = 0;
	while (i < count)
	{
		if (ft_strcmp(g_env[i], EMPTY_STR))
		{
			new_env[i] = ft_strdup(g_env[i]);
			if (!new_env[i])
				exit_error();
		}
		i++;
	}
	new_env[i] = ft_strdup(s);
	ft_clearenv();
	return (new_env);
}
