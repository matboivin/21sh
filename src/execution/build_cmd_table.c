/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cmd_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 17:05:37 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/14 16:22:20 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "sh_utils.h"
#include "sh_execution.h"

void	build_cmd_table(t_shctrl *ft_sh)
{
	ft_sh->cmds = malloc_cmd(DEFAULT_CAPACITY);
	if (!ft_sh->cmds)
		exit_shell(ft_sh);
	traverse_tree(ft_sh->ast, ft_sh->cmds);
}
