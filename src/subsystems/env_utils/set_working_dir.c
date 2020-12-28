/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_working_dir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 17:28:40 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/28 17:56:44 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include "libft_str.h"
#include "sh_env.h"

/*
** This function sets the current working directory value
**
** returns: 0 on success
**          -1 on error
*/

int			set_working_dir(void)
{
	int		ret;
	char	*new_var;
	char	cwd[PATH_MAX];

	ret = EXIT_SUCCESS;
	new_var = NULL;
	if (!getcwd(cwd, PATH_MAX))
		return (FAIL_RET);
	if (ft_findenv("PWD") != FAIL_RET)
		return (ft_setenv("PWD", cwd, true));
	new_var = ft_join_n_str(2, "PWD=", cwd);
	if (new_var)
		ret = ft_putenv(new_var);
	ft_strdel(&new_var);
	return (ret);
}
