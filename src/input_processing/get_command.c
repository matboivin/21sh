/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_command.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 20:47:52 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/16 23:56:41 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_str.h"
#include "libft_io.h"
#include "sh_utils.h"
#include "sh_env.h"
#include "sh_subsystems.h"
#include "sh_parser.h"
#include "wandre_mode.h"
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

static int	prompt_user(t_shctrl *ft_sh)
{
	int		ret;
	char	*prompt;

	ret = EXIT_SUCCESS;
	prompt = NULL;
	if (ft_sh->lexer->size == DEFAULT_SIZE)
	{
		prompt = create_prompt();
		ft_sh->lexer->input = ft_readline(prompt);
		ft_strdel(&prompt);
		if (wandre_mode_is_on(ft_sh->lexer->input))
		{
			ft_strdel(&(ft_sh->lexer->input));
			return (-1);
		}
	}
	else
		ft_sh->lexer->input = ft_readline(PS2);
	if (!ft_sh->lexer->input)
		handle_eof(ft_sh);
	ft_sh->lexer->pos = DEFAULT_VALUE;
	ret = tokenize(ft_sh->lexer);
	ft_strdel(&(ft_sh->lexer->input));
	return (ret);
}

/*
** This function gets the command input and splits it into tokens
*/

int			get_command(t_shctrl *ft_sh)
{
	int		multiline;

	multiline = EXIT_SUCCESS;
	ft_sh->lexer = malloc_lexer(DEFAULT_CAPACITY);
	if (!ft_sh->lexer)
		exit_shell(ft_sh);
	do
	{
		multiline = prompt_user(ft_sh);
	} while (multiline == 1);
#ifdef DEBUG
	print_lexer(ft_sh->lexer);
#endif /* DEBUG */
	if (multiline == EXIT_SUCCESS)
		return (parse(&(ft_sh->ast), ft_sh->lexer));
	return (multiline);
}
