/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 18:06:35 by mboivin           #+#    #+#             */
/*   Updated: 2020/11/06 17:16:24 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEXER_H
# define FT_LEXER_H

# define ARRAY_CAPACITY 300
# define MAX_TOKENS 14

# include <stdbool.h>

typedef enum		e_token_type
{
	NOT_FOUND = 0,
	TOKEN_EAT,
	TOKEN_SEMICOLON,
	TOKEN_DBLAND,
	TOKEN_DBLOR,
	TOKEN_REDIR,
	TOKEN_PIPE,
	TOKEN_AND,
	TOKEN_NEWLINE,
	TOKEN_TXT // commands, variables, functions, ...
}					t_token_type;

typedef struct		s_regex
{
	const char		*op;
	size_t			size;
	t_token_type	type;
}					t_regex;

typedef struct		s_token
{
	char			*content;
	size_t			size;
	t_token_type	type;
}					t_token;

/*
** Lexer stores all the tokens
*/

typedef struct		s_lexer
{
	t_token			*tokens;
	size_t			size;
	size_t			capacity;
}					t_lexer;

t_token				create_token(char *content, size_t size, t_token_type type);
void				create_lexer(t_lexer *lexer, size_t capacity);
void				add_token_to_lexer(t_lexer *lexer, t_token new_token);
void				destroy_lexer(t_lexer *lexer);

t_regex				get_token_type(char *linebuffer);
bool				fill_lexer(char *linebuffer, t_lexer *lexer);

#endif
