/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ast.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 20:34:29 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/23 18:28:19 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_AST_H
# define SH_AST_H

# include "sh_define.h"

typedef struct			s_ast_node
{
	// type
	// parent?
	struct s_ast_node	*left;
	struct s_ast_node	*right;
	// info
}						t_ast_node;

#endif
