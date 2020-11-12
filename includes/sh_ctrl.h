/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ctrl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:48:54 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/12 21:20:52 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_CTRL_H
# define SH_CTRL_H

# include "sh_define.h"
# include "sh_lexer.h"

typedef struct	s_shctrl
{
	t_lexer		*lexer;
}				t_shctrl;

void			create_shell(t_shctrl *ft_sh, size_t capacity);
void			destroy_shell(t_shctrl ft_sh);

#endif
