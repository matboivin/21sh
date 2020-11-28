/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:20:15 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/28 19:48:15 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
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

int			process_command(t_shctrl *ft_sh)
{
	size_t	i;

// #ifdef DEBUG
// 	t_ast_node	*root;
// 	root = ft_sh->ast;
// #endif /* DEBUG */

	i = 0;
	ft_sh->lexer = malloc_lexer(DEFAULT_CAPACITY);
	get_command(ft_sh);
	while (i < ft_sh->lexer->size)
		parse(&(ft_sh->ast), ft_sh->lexer, i++);
#ifdef DEBUG
	print_lexer(ft_sh->lexer);
	//print_ast(root);
#endif /* DEBUG */
	destroy_shell(ft_sh);
	return (g_status);
}
