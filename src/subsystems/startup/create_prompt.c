/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 03:01:19 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/21 22:14:31 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft_str.h"
#include "sh_env.h"
#include "sh_subsystems.h"

/*
** This function constructs a custom prompt
*/

static int	remove_home_from_path(char *pathname)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (pathname[i] && count < 3)
	{
		if (pathname[i] == '/')
			count++;
		i++;
	}
	if (count == 3)
		i--;
	return (i);
}

char		*create_prompt(void)
{
	char	*shell_prompt;
	char	*working_dir;
	char	cwd[PATH_MAX];
	int		i;

	shell_prompt = NULL;
	working_dir = NULL;
	i = 0;
	if (getcwd(cwd, PATH_MAX) != NULL)
	{
		i = remove_home_from_path(cwd);
		shell_prompt = ft_join_n_str(4, PS1_OP, "~", cwd + i, PS1_END);
	}
	else if (ft_getenv("PWD") != NULL)
	{
		working_dir = ft_getenv("PWD");
		i = remove_home_from_path(working_dir);
		shell_prompt = ft_join_n_str(4, PS1_OP, "~", working_dir, PS1_END);
	}
	else
		return (ft_strdup(PS1));
	return (shell_prompt);
}
