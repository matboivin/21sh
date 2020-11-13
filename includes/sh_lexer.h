/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:33:39 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/13 19:50:03 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_LEXER_H
# define SH_LEXER_H

# include <stdbool.h>
# include "sh_define.h"

typedef enum		e_token_type
{
	NOT_FOUND = 0,
	TOKEN_AND,
	TOKEN_EAT,
	TOKEN_EQUAL,
	TOKEN_DBLAND,
	TOKEN_DBLOR,
	TOKEN_FOR,
	TOKEN_NAME,
	TOKEN_NEG,
	TOKEN_PIPE,
	TOKEN_REDIR,
	TOKEN_SEMICOLON,
	TOKEN_WHILE
}					t_token_type;

typedef struct		s_regex
{
	const char		*op;
	size_t			size;
	t_token_type	type;
}					t_regex;

typedef struct		s_token
{
	size_t			size;
	t_token_type	type;
	char			*content;
}					t_token;

/*
** Lexer stores all the tokens
*/

typedef struct		s_lexer
{
	size_t			size;
	size_t			capacity;
	t_token			*tokens;
}					t_lexer;

t_token				create_token(char *content, size_t size, t_token_type type);
void				add_token_to_lexer(t_lexer *lexer, t_token new_token);

void				create_lexer(t_lexer *lexer, size_t capacity);
t_lexer				*malloc_lexer(size_t capacity);
void				destroy_lexer(t_lexer lexer);
void				free_lexer(t_lexer *to_free);

t_regex				get_token_type(char *input);
bool				fill_lexer(char *input, t_lexer *lexer);

#endif
