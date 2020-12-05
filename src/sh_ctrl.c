/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ctrl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:53:37 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/05 18:27:23 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sh_ctrl.h"

/*
** Shell controller
**
** create_shell()   :  Constructor
** destroy_shell()  :  Destructor
*/

void	create_shell(t_shctrl *ft_sh)
{
	ft_sh->lexer = NULL;
	ft_sh->ast = NULL;
}

void	destroy_shell(t_shctrl *ft_sh)
{
	if (ft_sh->lexer)
		free_lexer(&(ft_sh->lexer));
	if (ft_sh->ast)
		free_ast(&(ft_sh->ast));
}
