/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 18:56:03 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/06 19:54:39 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <string.h>
#include "libft_str.h"
#include "ft_define.h"
#include "sh_env.h"
#include "ft_sh.h"

t_env	*g_env;

/*
** This function fills the environment linked list struct
**
** environ: The environment represented as an array of strings
**
** returns: The new environment
**          NULL otherwise
*/

void		fill_env(char **environ)
{
	(void)environ;
	print_error();
}

/*
** This function creates a new environment as a linked list struct
**
** new_env: The output environment
** environ: The environment represented as an array of strings
*/

void		init_env(char **environ)
{
	g_env = malloc(sizeof(t_env));
	if (!g_env)
		print_error();
	fill_env(environ);
}

/*
** This function adds or removes definitions from the environment.
** The entry with the name key is replaced by the value ‘key=value’.
**
** key: The variable name
** value: The variable value
** replace: If replace is false and name exists, nothing happens
**          Otherwise the old entry is replaced by the new one
**
** returns: 0 on success
**          A non-zero value otherwise
*/

int			ft_setenv(char *key, char *value, bool replace)
{
	t_env	*cursor;

	(void)replace;
	if (!key || *value)
		return (-1);
	cursor = g_env;
	if (ft_getenv(key))
	{
		while (cursor->key != key)
			cursor = cursor->next;
		cursor->value = value;
	}
	return (0);
}
