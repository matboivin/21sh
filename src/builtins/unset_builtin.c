/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 00:24:55 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/27 23:02:49 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_ctype.h"
#include "sh_utils.h"
#include "sh_env.h"
#include "sh_builtins.h"

/*
** Recoded builtin unset() without any options
**
** unset [name ...]
**     For each NAME, remove the corresponding variable or function.
**
** returns: success
**          non-zero if an invalid option is given or a NAME is read-only
*/

int		unset_builtin(int argc, char **argv)
{
	int	i;

	if (argc == NO_ARGS)
		return (EXIT_SUCCESS);
	i = FIRST_PARAM;
	if (argv[FIRST_PARAM][0] == '-')
	{
		handle_invalid_opt(argv[CMD_NAME], argv[i]);
		print_builtin_usage("unset", "unset [name ...]");
		return (EXIT_FAILURE);
	}
	while (i < argc)
	{
		if (ft_isdigit(argv[i][0]))
			return (handle_invalid_id(argv[CMD_NAME], argv[i]));
		else
			ft_unsetenv(argv[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
