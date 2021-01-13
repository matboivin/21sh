/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_stream.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/14 18:28:11 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/14 00:14:05 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "sh_expansion.h"
#include "sh_execution.h"

void	redirect_stream(int from, int to)
{
	if ((!is_open_file(from)) || (!is_open_file(to)) || (from == to))
		return ;
	if (dup2(from, to) != FAIL_RET)
		close(from);
}
