/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_term_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 19:17:52 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/11 20:33:56 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curses.h>
#include <term.h>
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
		print_error("Specify a terminal type with `setenv TERM <yourtype>'.");
	ret = tgetent(NULL, termtype);
	if (ret == 0)
		print_error("Terminal type is not defined.");
	else if (ret == FAIL_RET)
		print_error("Could not access the termcap data base.");
}
