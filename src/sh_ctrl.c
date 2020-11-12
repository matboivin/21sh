/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ctrl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:53:37 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/12 21:22:54 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "sh_lexer.h"
#include "sh_ctrl.h"

void	create_shell(t_shctrl *ft_sh, size_t capacity)
{
	ft_sh->lexer = malloc_lexer(capacity);
}

void	destroy_shell(t_shctrl ft_sh)
{
	free_lexer(ft_sh.lexer);
}
