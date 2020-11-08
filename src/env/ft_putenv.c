/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:56:56 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/08 21:59:06 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft_mem.h"
#include "libft_str.h"
#include "sh_define.h"
#include "sh_env.h"

/*
** This function appends a new definition to the environment
**
** s: The entry to add
**
** returns: 0 on success
**          -1 on error
*/

char		**ft_putenv(char *s)
{
	size_t	i;
	size_t	count;
	char	**new_env;

	if (!s)
		return (NULL);
	count = ft_str_arr_len(g_env) + 2;
	new_env = ft_calloc(count, sizeof(char *));
	if (!new_env)
		return (NULL);
	i = 0;
	while (g_env[i])
	{
		new_env[i] = ft_strdup(g_env[i]);
		i++;
	}
	new_env[i] = ft_strdup(s);
	ft_clearenv();
	return (new_env);
}
