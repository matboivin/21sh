/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 00:24:16 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/23 15:58:27 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sh_builtins.h"

/*
** Recoded builtin export() without any options
**
** export [name[=value] ...]
**    Marks each NAME for automatic export to the environment of subsequently
**    executed commands.
**    If VALUE is supplied, assign VALUE before exporting.
**
** returns: success
**          non-zero if invalid option is given or NAME is invalid
*/

int		export_builtin(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	return (EXIT_SUCCESS);
}
