/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 17:02:51 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/10 17:07:46 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_io.h"
#include "libft_printf.h"
#include "libft_str.h"
#include "sh_env.h"
#include "sh_input_processing.h"

int			shell_loop(void)
{
	char	*command;
	int		i = 0; // tmp test

	while (i < 2) // tmp test: loop 2 times
	{
		command = ft_readline(SHELL_PROMPT);
		ft_printf("%s\n", command); // tmp test
		ft_strdel(&command);
		i++;
	}
	ft_clearenv();
	return (EXIT_SUCCESS);
}
