/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 19:14:01 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/09 22:01:01 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <string.h>
#include "libft_str.h"
#include "sh_define.h"
#include "sh_env.h"
#include "ft_sh.h"

/*
** This function adds a new definition to the environment
** If the new entry already exists and replace is false, nothing happens.
** Otherwise, the entry is replaced by the new one.
**
** key: Name of the variable
** new_value: Value of the variable
** replace: true or false
**
** returns: 0 on success
**          -1 on error
*/

int		ft_setenv(char *key, char *new_value, bool replace)
{
	int	to_set;

	if (!g_env || !key || !new_value)
		return (FAIL_RET);
	to_set = find_env(key);
	if ((to_set != FAIL_RET) && replace)
	{
		g_env[to_set] = ft_join_n_str(3, key, "=", new_value);
		if (!g_env[to_set])
			print_error();
	}
	return (0);
}
