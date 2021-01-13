/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 20:20:15 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/14 00:11:20 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_expansion.h"
#include "sh_input_processing.h"

/*
** This function processes the command input
*/

void		process_input(t_shctrl *ft_sh)
{
	int		parsed_cmd;

	parsed_cmd = get_command(ft_sh);
	if (parsed_cmd != FAIL_RET)
		traverse_tree(ft_sh, ft_sh->ast);
	destroy_shell(ft_sh);
}
