/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:02:51 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/14 20:29:26 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_io.h"
#include "libft_str.h"
#include "sh_utils.h"
#include "sh_input_processing.h"

int			shell_loop(t_shctrl *ft_sh)
{
	char	*user_input;

	while (!g_done)
	{
		user_input = ft_readline(SHELL_PROMPT);
		parse_command(ft_sh, user_input);
		ft_strdel(&user_input);
	}
	free_all(ft_sh);
	return (g_status);
}
