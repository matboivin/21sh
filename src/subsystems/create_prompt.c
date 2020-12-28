/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 03:01:19 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/28 17:50:27 by mboivin          ###   ########.fr       */
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

char		*create_prompt(void)
{
	char	*shell_prompt;
	char	cwd[PATH_MAX];

	shell_prompt = NULL;
	if (getcwd(cwd, PATH_MAX) != NULL)
		shell_prompt = ft_join_n_str(3, PS1_OP, cwd, PS1_END);
	else if (ft_getenv("PWD") != NULL)
		shell_prompt = ft_join_n_str(3, PS1_OP, ft_getenv("PWD"), PS1_END);
	else
		return (NULL);
	return (shell_prompt);
}
