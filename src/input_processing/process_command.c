/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:20:15 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/02 19:14:32 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stdlib.h>
#include "libft_str.h"
#include "libft_printf.h"
#include "sh_utils.h"
#include "sh_lexer.h"
#include "sh_input_processing.h"

/*
** This function gets the command input and sends it to the lexer
*/

static void	get_command(t_shctrl *ft_sh)
{
	int		not_finished;
	char	*user_input;

	user_input = prompt(ft_sh, SHELL_PROMPT);
	not_finished = tokenize(ft_sh->lexer, user_input);
	ft_strdel(&user_input);
	while (not_finished)
	{
		user_input = prompt(ft_sh, LINE_PROMPT);
		not_finished = tokenize(ft_sh->lexer, user_input);
		ft_strdel(&user_input);
	}
}

/*
** This function processes the command input
*/

int				process_command(t_shctrl *ft_sh)
{
	size_t		i;
	bool		ret_val;

	i = 0;
	ret_val = true;
	ft_sh->lexer = malloc_lexer(DEFAULT_CAPACITY);
	get_command(ft_sh);
	create_tree_root(&(ft_sh->ast));
	while ((i < ft_sh->lexer->size) && ret_val)
	{
		ret_val = parse(&(ft_sh->ast), ft_sh->lexer, &i);
	}
	// TODO: Syntax fixing
	if (i != ft_sh->lexer->size)
	{
		ft_dprintf(STDERR_FILENO, "Parsing error\n");
		exit_ft_sh(EXIT_FAILURE, ft_sh);
	}
#ifdef DEBUG
	print_lexer(ft_sh->lexer);
	print_ast(ft_sh->ast);
	system("dot -Tsvg ast.dot -o ast.svg");
#endif /* DEBUG */
	destroy_shell(ft_sh);
	return (g_status);
}
