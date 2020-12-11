/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_visitor.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 18:16:37 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/11 15:31:10 by ouram            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_VISITOR_H
# define SH_VISITOR_H

# include "sh_ast.h"

/*
** This function traverses the AST following the in-order pattern
*/

void	in_order(t_ast_node	*node);

#endif
