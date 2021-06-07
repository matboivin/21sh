/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wandre_mode.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 18:44:25 by mboivin           #+#    #+#             */
/*   Updated: 2021/06/07 17:46:36 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdio.h>
#include "libft_str.h"
#include "sh_env.h"
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
		return ("you need to learn the basics imo");
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

void		wandroulette(void)
{
	int		n;

	srand(time(NULL));
	n = (rand() % MAX_MSG) + 1;
	if (n == MAX_MSG)
		printf("%s!voteban %s ><\n", WANDRE_PREFIX, ft_getenv("USER"));
	else
		printf("%s%s\n", WANDRE_PREFIX, a_wandre_a_day(n));
}

void		wanderror(char *filename)
{
	if (filename && !ft_strcmp(filename, "sl"))
		printf("%sthe command you're looking for is 'ls' bro ;o\n", WANDRE_PREFIX);
	else if (filename && !ft_strcmp(filename, "cqt"))
		printf("%sdid u mean 'cat' bro? :o\n", WANDRE_PREFIX);
	else
		wandroulette();
}

void		wake_wandre(void)
{
	if (wandre_mode)
	{
		printf("%sI'm already awake ><\n", WANDRE_PREFIX);
		return ;
	}
	wandre_mode = true;
	printf("Warning /!\\ The wandre mode is activated! Type '!stopit_wandre' to deactivate\n\n%shi %s! :)\n\n", WANDRE_PREFIX, ft_getenv("USER"));
}

void		stop_wandre(void)
{
	if (!wandre_mode)
	{
		printf("Type '!wandre' to wake up wandre\n");
		return ;
	}
	wandre_mode = false;
	printf("wandre mode deactivated\n\n%sbye :)\n\n", WANDRE_PREFIX);
}

int			wandre_mode_is_on(char *cmd_name)
{
	if (!ft_strncmp(cmd_name, WAKE_WANDRE_CMD, WAKE_CMD_LEN))
	{
		wake_wandre();
		return (1);
	}
	if (!ft_strncmp(cmd_name, STOP_WANDRE_CMD, STOP_CMD_LEN))
	{
		stop_wandre();
		return (1);
	}
	return (0);
}
