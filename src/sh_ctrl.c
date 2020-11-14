/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ctrl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:53:37 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/14 20:17:10 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sh_lexer.h"
#include "sh_ctrl.h"

void	create_shell(t_shctrl *ft_sh)
{
	ft_sh->lexer = NULL;
}

void	destroy_shell(t_shctrl *ft_sh)
{
	if (ft_sh->lexer)
		free_lexer(&(ft_sh->lexer));
}
