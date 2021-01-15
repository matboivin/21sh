/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wandre_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:44:25 by mboivin           #+#    #+#             */
/*   Updated: 2021/01/15 22:35:25 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft_str.h"
#include "libft_printf.h"
#include "sh_utils.h"
#include "wandre_mode.h"

/*
** Get a nice message by wandre
*/

static char	*a_wandre_a_day(int n)
{
	switch (n)
	{
	case 0:
		return ("srsly bro ;o");
	case 1:
		return ("lol");
	case 2:
		return ("RTFM wesh");
	case 3:
		return ("just read the man :(");
	case 4:
		return ("rofl xD");
	case 5:
		return ("omg xD");
	case 6:
		return ("-42 roooh ;o");
	case 7:
		return ("no comment.");
	case 8:
		return ("plz :(");
	case 9:
		return ("I will evaluate your Snow crash :x");
	case 10:
		return ("I hope for you I won't evaluate your Darkly :(");
	case 11:
		return ("need a pro tip? RTFM!");
	case 12:
		return ("you need to learn the basic imo");
	case 13:
		return ("srsly stop :(");
	case 14:
		return ("Lol dafuck");
	case 15:
		return ("Haha wtf.");
	default:
		return ("WTF. ><");
	}
}

void		wandroulette(char *filename)
{
	int		n;

	n = 0;
	if (filename && !ft_strcmp(filename, "sl"))
		ft_printf("%sthe command you're looking for is 'ls' bro ;o\n", WANDRE_PREFIX);
	else if (filename && !ft_strcmp(filename, "cqt"))
		ft_printf("%sdid u mean 'cat' bro? :o\n", WANDRE_PREFIX);
	else
	{
		srand(time(NULL));
		n = (rand() % MAX_MSG) + 1;
		ft_printf("%s%s\n", WANDRE_PREFIX, a_wandre_a_day(n));
	}
}

void		wake_wandre(void)
{
	ft_printf("Warning /!\\ The wandre mode is activated!\n\n%shi! :)\n\n", WANDRE_PREFIX);
}
