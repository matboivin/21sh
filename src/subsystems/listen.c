/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/06 17:18:51 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/06 17:58:05 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "libft_str.h"
#include "libft_io.h"
#include "libft_printf.h"
#include "ft_define.h"
#include "ft_subsystems.h"
#include "ft_sh.h"

int			listen(void)
{
	char	*command;

	while (!g_done)
	{
		ft_printf("%s > ", SHELL_NAME);
		get_next_line(STDIN_FILENO, &command); // tmp
		// TODO: Lexer-parser-AST
		// if (command)
		// execute
		// else
		// g_done = true;
		// ft_dprintf(STDERR_FILENO, "Impossible to treat commands");
		ft_strdel(&command); // tmp
	}
	return (EXIT_SUCCESS);
}
