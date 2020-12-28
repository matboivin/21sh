/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 20:47:52 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/28 01:20:57 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_str.h"
#include "libft_io.h"
#include "sh_utils.h"
#include "sh_env.h"
#include "sh_subsystems.h"
#include "sh_parser.h"
#include "sh_input_processing.h"

/*
** This function exits if end of input was indicated
*/

static void	handle_eof(t_shctrl *ft_sh)
{
	ft_putchar('\n');
	exit_shell(ft_sh);
}

/*
** This function prompts the user for a command
*/

static int	prompt_user(t_shctrl *ft_sh, char *prompt)
{
	int		ret;

	ret = 0;
	if (prompt)
	{
		ft_sh->lexer->input = ft_readline(prompt);
		ft_strdel(&prompt);
	}
	else
		ft_sh->lexer->input = ft_readline(PS1);
	if (!ft_sh->lexer->input)
		handle_eof(ft_sh);
	ret = tokenize(ft_sh->lexer);
	ft_strdel(&ft_sh->lexer->input);
	return (ret);
}

/*
** This function gets the command input and splits it into tokens
*/

int			get_command(t_shctrl *ft_sh)
{
	int		ret;

	ft_sh->lexer = malloc_lexer(DEFAULT_CAPACITY);
	if (!ft_sh->lexer)
		exit_shell(ft_sh);
	ret = prompt_user(ft_sh, create_prompt());
	while (ret == 1)
		ret = prompt_user(ft_sh, PS2);
	if (ret == EXIT_SUCCESS)
		ret = parse(&(ft_sh->ast), ft_sh->lexer);
	return (ret);
}
