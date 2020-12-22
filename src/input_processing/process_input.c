/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:20:15 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/22 18:43:20 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_parser.h"
#include "sh_execution.h"
#include "sh_input_processing.h"

/*
** This function processes the command input
*/

void		process_input(t_shctrl *ft_sh)
{
	int		ret_val;

	ret_val = get_command(ft_sh);
#ifdef DEBUG
	print_lexer(ft_sh->lexer);
	print_ast(ft_sh->ast);
#endif /* DEBUG */
	if (ret_val != FAIL_RET)
		traverse_tree(ft_sh, ft_sh->ast);
	destroy_shell(ft_sh);
}
