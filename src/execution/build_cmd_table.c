/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_cmd_table.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 17:05:37 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/11 17:43:38 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "sh_execution.h"

void	build_cmd_table(t_shctrl *ft_sh)
{
	ft_sh->cmds = malloc_cmd(DEFAULT_CAPACITY);
	traverse_tree(ft_sh->ast);
}
