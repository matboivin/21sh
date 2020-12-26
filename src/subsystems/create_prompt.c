/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 03:01:19 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/26 03:04:42 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_str.h"
#include "sh_env.h"
#include "sh_subsystems.h"

/*
** This function constructs a custom prompt
*/

char		*create_prompt(void)
{
	char	*shell_prompt;

	if (!ft_getenv("PWD"))
		return (NULL);
	shell_prompt = ft_join_n_str(3, PS1_OP, ft_getenv("PWD"), PS1_END);
	if (!shell_prompt)
		return (NULL);
	return (shell_prompt);
}
