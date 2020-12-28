/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 00:24:16 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/28 17:17:13 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft_str.h"
#include "sh_utils.h"
#include "sh_env.h"
#include "sh_builtins.h"

/*
** Recoded builtin export() without any options
*/

/*
** This function marks names for export via the environment
*/

static int	declare_export(char *var)
{
	size_t	count;

	if (!var)
		return (FAIL_RET);
	count = ft_str_arr_len(g_env);
	g_env = dup_environment((count + 1), true);
	if (!g_env)
		return (FAIL_RET);
	g_env[count] = ft_strdup(var);
	if (!g_env[count])
	{
		print_errno("export");
		return (FAIL_RET);
	}
	return (0);
}

/*
** If the name of a variable is followed by =word, then the value of that
** variable shall be set to word.
*/

static int	set_var_value(char *key_value, size_t sep, size_t len)
{
	char	*key;
	char	*value;
	int		ret;

	key = ft_substr(key_value, 0, sep);
	value = NULL;
	ret = ft_findenv(key);
	if (ret != FAIL_RET)
	{
		if (len > 1)
		{
			value = ft_substr(key_value, (sep + 1), len);
			ret = ft_setenv(key, value, true);
			ft_strdel(&value);
		}
		else
			g_env[ret] = ft_strreplace(g_env[ret], key_value);
	}
	ft_strdel(&key);
	return (ret);
}

static void	handle_variable(char *key_value)
{
	char	*equal_sign;
	size_t	sep;
	size_t	len;
	int		ret;

	equal_sign = NULL;
	equal_sign = ft_strchr(key_value, ENV_VAR_SEP);
	if (!equal_sign)
	{
		declare_export(key_value);
		return ;
	}
	sep = equal_sign - key_value;
	len = ft_strlen(key_value) - sep;
	if (len < 1)
		return ;
	ret = set_var_value(key_value, sep, len);
	if (ret == FAIL_RET)
		ft_putenv(key_value);
}

/*
** export [name[=value] ...]
**    Marks each NAME for automatic export to the environment of subsequently
**    executed commands.
**
** returns: success
**          non-zero if invalid option is given or NAME is invalid
*/

int			export_builtin(int argc, char **argv)
{
	int		ret;
	int		i;

	if (argc == NO_ARGS)
		return (display_export());
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
		if (!is_valid_identifier(argv[i]))
			ret = handle_invalid_id(argv[CMD_NAME], argv[i]);
		else
			handle_variable(argv[i]);
		i++;
	}
	return (ret);
}
