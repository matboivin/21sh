/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 03:01:19 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/05 15:34:58 by mboivin          ###   ########.fr       */
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

static int	cut_path(char *pathname)
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
	if (i)
		i--;
	return (i);
}

char		*create_prompt(void)
{
	char	*shell_prompt;
	char	*workind_dir;
	char	cwd[PATH_MAX];
	int		i;

	shell_prompt = NULL;
	workind_dir = NULL;
	i = 0;
	if (getcwd(cwd, PATH_MAX) != NULL)
	{
		i = cut_path(cwd);
		shell_prompt = ft_join_n_str(4, PS1_OP, "~", cwd + i, PS1_END);
	}
	else if (ft_getenv("PWD") != NULL)
	{
		workind_dir = ft_getenv("PWD");
		i = cut_path(workind_dir);
		shell_prompt = ft_join_n_str(4, PS1_OP, "~", workind_dir, PS1_END);
	}
	else
		return (NULL);
	return (shell_prompt);
}
