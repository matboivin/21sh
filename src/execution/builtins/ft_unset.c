/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 00:24:55 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/22 01:27:02 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft_printf.h"
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
	i = 1;
	while (i < argc)
	{
		if (!check_var_name(argv[i]))
		{
			g_status = EXIT_FAILURE;
			print_builtin_error(
				argv[CMD_NAME], argv[1], "not a valid identifier");
			return ;
		}
		else
			ft_unsetenv(argv[i]);
		i++;
	}
}
