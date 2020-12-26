/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invoke_builtin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 01:38:15 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/26 01:38:29 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_execution.h"

/*
** This function invokes a shell builtin
*/

void	invoke_builtin(t_simplecmd *simple_cmd)
{
	(*simple_cmd->builtin_func)(simple_cmd->argc, simple_cmd->cmd_args);
}
