/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_working_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 17:28:40 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/27 18:33:22 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include "sh_env.h"

/*
** This function sets the current working directory value
**
** returns: 0 on success
**          -1 on error
*/

int			set_working_dir(void)
{
	char	cwd[PATH_MAX];

	if (getcwd(cwd, PATH_MAX))
		return (ft_setenv("PWD", cwd, true));
	return (FAIL_RET);
}
