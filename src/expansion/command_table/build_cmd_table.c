/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cmd_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 17:05:37 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/14 00:11:53 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "sh_utils.h"
#include "sh_expansion.h"

/*
** This function builds a command table for each command node
*/

void	build_cmd_table(t_shctrl *ft_sh)
{
	ft_sh->cmd = malloc_cmd(ft_sh->lexer->size);
	if (!ft_sh->cmd)
		exit_shell(ft_sh);
}
