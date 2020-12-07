/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_prompt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 18:50:35 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/07 15:46:03 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include "sh_env.h"
#include "sh_subsystems.h"

/*
** This function creates a custom shell prompt
*/

void		create_prompt(void)
{
	char	*custom_prompt;

	custom_prompt = ft_join_n_str(
		5, "FT_PS1", "=", OP_PROMPT, ft_getenv("SHELL_NAME"), END_PROMPT);
	if (custom_prompt)
		ft_putenv(custom_prompt);
}
