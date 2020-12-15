/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ctrl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:48:54 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/15 23:12:54 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_CTRL_H
# define SH_CTRL_H

# include "sh_define.h"
# include "sh_lexer.h"
# include "sh_parser.h"
# include "sh_command.h"

/*
** Shell controller
**
** lexer: Contains the tokens
** ast: Abstract Syntax Tree generated from parsing
** cmd: Command table
*/

typedef struct	s_shctrl
{
	t_lexer		*lexer;
	t_ast_node	*ast;
	t_cmd		*cmd;
}				t_shctrl;

/*
** create_shell()   :  Constructor
** destroy_shell()  :  Destructor
*/

void			create_shell(t_shctrl *ft_sh);
void			destroy_shell(t_shctrl *ft_sh);

#endif
