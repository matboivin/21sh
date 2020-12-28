/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 00:24:16 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/28 01:21:36 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft_num.h"
#include "libft_printf.h"
#include "sh_utils.h"
#include "sh_env.h"
#include "sh_builtins.h"

/*
** Recoded builtin export() without any options
*/

// static int		env_size(t_env *env)
// {
// 	int i;

// 	i = 0;
// 	while (env)
// 	{
// 		i++;
// 		env = env->next;
// 	}
// 	return (i);
// }

// static t_env	*get_by_id(t_env *env, int n)
// {
// 	int i;

// 	i = -1;
// 	while (++i < n)
// 		env = env->next;
// 	return (env);
// }

// static void	sort_by_ascii(t_env *env, int *t, int size)
// {
// 	int	i;
// 	int	tmp;
// 	int	is_sorted;

// 	i = -1;
// 	is_sorted = 0;
// 	while (++i < size)
// 		t[i] = i;
// 	while (is_sorted == 0)
// 	{
// 		is_sorted = 1;
// 		i = -1;
// 		while (++i < size - 1)
// 		{
// 			if (ft_strcmp(get_by_id(env, t[i])->key, get_by_id(env, t[i + 1])->key) > 0)
// 			{
// 				tmp = t[i];
// 				t[i] = t[i + 1];
// 				t[i + 1] = tmp;
// 				is_sorted = 0;
// 			}
// 		}
// 	}
// }

// int			display_export()
// {
// 	t_env	*current;
// 	int		t[env_size(g_env)];
// 	int		size;
// 	int		i;

// 	size = env_size(g_env);
// 	i = -1;
// 	sort_by_ascii(g_env, t, env_size(g_env));
// 	while (++i < size)
// 	{
// 		current = get_by_id(g_env, t[i]);
// 		if (ft_strcmp(current->key, "_") == 0)
// 			continue ;
// 		ft_putstr("declare -x ");
// 		ft_putstr(current->key);
// 		if (current->value)
// 		{
// 			ft_putstr("=\"");
// 			ft_putstr(current->value);
// 			ft_putstr("\"");
// 		}
// 		ft_putstr("\n");
// 		current = current->next;
// 	}
// 	return (1);
// }

/*
** export [name[=value] ...]
**    Marks each NAME for automatic export to the environment of subsequently
**    executed commands.
**    If VALUE is supplied, assign VALUE before exporting.
**
** If the name of a variable is followed by =word, then the value of that
** variable shall be set to word.
**
** returns: success
**          non-zero if invalid option is given or NAME is invalid
*/

static void	export_variable(char *key_value)
{
	size_t	len;
	size_t	sep;
	char	*equal_sign;
	char	*key;
	char	*value;
	int		to_set;

	key = NULL;
	value = NULL;
	equal_sign = NULL;
	equal_sign = ft_strchr(key_value, ENVKEY_SEP);
	if (!equal_sign)
		return ;
	sep = equal_sign - key_value;
	len = ft_strlen(key_value) - sep;
	if (len > 0)
	{
		key = ft_substr(key_value, 0, sep);
		to_set = ft_findenv(key);
		if (to_set != FAIL_RET)
		{
			if (len > 1)
			{
				value = ft_substr(key_value, (sep + 1), len);
				ft_setenv(key, value, true);
			}
			else
				g_env[to_set] = ft_strreplace(g_env[to_set], key_value);
			ft_strdel(&value);
		}
		else
			ft_putenv(key_value);
		ft_strdel(&key);
	}
}

int			export_builtin(int argc, char **argv)
{
	int		ret;
	int		i;

	// if (argc == NO_ARGS)
	// 	return (display_export());
	ret = EXIT_SUCCESS;
	i = FIRST_PARAM;
	if (argv[FIRST_PARAM][0] == '-')
	{
		handle_invalid_opt(argv[CMD_NAME], argv[FIRST_PARAM]);
		print_builtin_usage("export", "export [name[=value]");
		return (EXIT_FAILURE);
	}
	while (i < argc)
	{
		if (ft_isdigit(argv[i][0]))
			ret = handle_invalid_id(argv[CMD_NAME], argv[i]);
		else
			export_variable(argv[i]);
		i++;
	}
	return (ret);
}
