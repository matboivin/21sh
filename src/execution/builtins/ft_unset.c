/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 00:24:55 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/22 14:44:36 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_ctype.h"
#include "sh_utils.h"
#include "sh_env.h"
#include "sh_subsystems.h"
#include "sh_builtins.h"

/*
** Recoded builtin unset() without any options
*/

void		ft_unset(int argc, char **argv)
{
	int		i;

	if (argc == DEFAULT_ARGC)
		return ;
	i = FIRST_PARAM;
	while (i < argc)
	{
		if (ft_isdigit(argv[i][0]))
		{
			g_status = EXIT_FAILURE;
			print_builtin_error(
				argv[CMD_NAME], argv[FIRST_PARAM], "not a valid identifier");
			return ;
		}
		else
			ft_unsetenv(argv[i]);
		i++;
	}
}
