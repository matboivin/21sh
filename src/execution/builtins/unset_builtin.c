/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_builtin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 00:24:55 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/23 15:31:11 by mboivin          ###   ########.fr       */
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

	if (argc == DEFAULT_ARGC)
		return (EXIT_SUCCESS);
	i = FIRST_PARAM;
	while (i < argc)
	{
		if (ft_isdigit(argv[i][0]))
		{
			g_status = EXIT_FAILURE;
			print_error(
				3, argv[CMD_NAME], argv[FIRST_PARAM], "not a valid identifier");
			return (EXIT_FAILURE);
		}
		else
			ft_unsetenv(argv[i]);
		i++;
	}
	return (EXIT_SUCCESS);
}
