/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 01:35:35 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/26 01:35:58 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "sh_execution.h"

/*
** This function checks whether the current simple command is a shell builtin
*/

bool	is_builtin(t_simplecmd *simple_cmd)
{
	return (simple_cmd->builtin_func);
}
