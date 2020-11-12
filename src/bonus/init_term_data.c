/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:17:52 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/12 18:18:28 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include "libft_printf.h"
#include "sh_env.h"
#include "sh_utils.h"
#include "sh_termcaps.h"

/*
** This functions looks for the terminal type and loads the corresponding
** termcaps
*/

void		init_term_data(void)
{
	char	*termtype;
	int		ret;

	termtype = ft_getenv("TERM");
	if (!termtype)
	{
		ft_dprintf(
			STDERR_FILENO,
			"Specify a terminal type with `setenv TERM <yourtype>'.\n");
		exit_ft_sh(EXIT_FAILURE);
	}
	ret = tgetent(NULL, termtype);
	if (ret == 0)
	{
		ft_dprintf(
			STDERR_FILENO,
			"Terminal type %s is not defined.\n", termtype);
		exit_ft_sh(EXIT_FAILURE);
	}
	else if (ret == FAIL_RET)
	{
		ft_dprintf(STDERR_FILENO, "Could not access the termcap data base.\n");
		exit_ft_sh(EXIT_FAILURE);
	}
}
