/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 23:55:17 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/27 20:57:24 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"
#include "sh_builtins.h"

/*
** Recoded builtin echo() with option ’-n’
**
** echo [-n] [arg ...]
**     Display the ARGs, separated by a single space character and followed by a
**     newline, on the standard output.
**
** Options:
**  -n    do not append a newline
**
** returns: success
**          non-zero if a write error occurs
*/

static void	handle_newline_opt(char *arg, bool *newline, int *i)
{
	if (!ft_strcmp(arg, "-n"))
	{
		*newline = false;
		(*i)++;
	}
}

int			echo_builtin(int argc, char **argv)
{
	int		i;
	int		write_ret;
	bool	newline;

	i = FIRST_PARAM;
	write_ret = 0;
	newline = true;
	if (argc > NO_ARGS)
		handle_newline_opt(argv[FIRST_PARAM], &newline, &i);
	while ((i < argc) && (write_ret != FAIL_RET))
	{
		write_ret = ft_printf("%s", argv[i]);
		if (i + 1 < argc)
			write_ret = ft_printf(" ");
		i++;
	}
	if (newline && (write_ret != FAIL_RET))
		write_ret = ft_printf("\n");
	if (write_ret == FAIL_RET)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
