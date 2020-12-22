/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboivin <mboivin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 20:33:39 by mboivin           #+#    #+#             */
/*   Updated: 2020/12/22 18:37:31 by mboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_LEXER_H
# define SH_LEXER_H

# include <stdbool.h>
# include "sh_define.h"

# define DEFAULT_SIZE 0

/*
** Tokens
*/

typedef enum	e_tok_type
{
	TOKEN_NOT_FOUND = 0,
	TOKEN_EAT,
	TOKEN_DGREAT,
	TOKEN_GREAT,
	TOKEN_LESS,
	TOKEN_NEWLINE,
	TOKEN_PIPE,
	TOKEN_SEMI,
	TOKEN_WORD
}				t_tok_type;

/*
** Regex to find
**
** op: The meta-character
** len: Length of the token
** type: Type of the token
*/

typedef struct	s_regex
{
	const char	*op;
	size_t		len;
	t_tok_type	type;
}				t_regex;

/*
** Token
**
** len: Length of the token
** type: Type of the token
** value: The data
*/

typedef struct	s_token
{
	size_t		len;
	t_tok_type	type;
	char		*value;
}				t_token;

/*
** Lexer: lexical analyzer
**
** pos: Index of the current token
** size: Size of the lexer
** capacity: Maximum capacity of the lexer
** input: The string input to tokenize
** tokens: The resulting tokens
*/

typedef struct	s_lexer
{
	size_t		pos;
	size_t		size;
	size_t		capacity;
	char		*input;
	t_token		**tokens;
}				t_lexer;

/*
** Token
**
** create_token()   :  Constructor
** malloc_token()   :  Malloc function
** destroy_token()  :  Destructor
** free_token()     :  Free function
*/

t_token			create_token(const char *s, size_t p_len, t_tok_type p_type);
t_token			*malloc_token(const char *s, size_t p_len, t_tok_type p_type);
void			free_token(t_token **to_free);
void			delete_tokens(t_token **tokens, size_t size);

/*
** Lexer: lexical analyzer
**
** create_lexer()   :  Constructor
** malloc_lexer()   :  Malloc function
** destroy_lexer()  :  Destructor
** free_lexer()     :  Free function
*/

void			create_lexer(t_lexer *lexer, size_t p_capacity);
t_lexer			*malloc_lexer(size_t p_capacity);
void			destroy_lexer(t_lexer to_destroy);
void			free_lexer(t_lexer **to_free);

/*
** Checks whether the lexer is full
*/

bool			lexer_is_full(t_lexer *lexer);

/*
** Doubles the capacity of the lexer
*/

void			increase_lexer(t_lexer *lexer);

/*
** Adds a token to the lexer
*/

void			add_token_to_lexer(
	t_lexer *lexer, const char *s, size_t p_len, t_tok_type p_type);

/*
** Searches if input character is a token
*/

t_regex			get_token(char *input);

/*
** Splits the input string into tokens and handles syntax errors
*/

int				tokenize(t_lexer *lexer);

/*
** Token handlers
*/

void			handle_token(t_lexer *lexer, t_regex token, char **stack);
void			handle_text(t_lexer *lexer, char **stack);
int				handle_quotes(t_lexer *lexer);

/*
** Escapes a character following a backslash
*/

int				escape_char(t_lexer *lexer, char **stack);

/*
** Adds the current character to the stack
*/

char			*push_char(t_lexer *lexer, char *stack);

/*
** Gets next token
*/

void			get_next_token(t_lexer *lexer);

/*
** Eats the current token if its type is the one expected
*/

int				eat(t_lexer *lexer, t_tok_type expected);

/*
** Prints the lexer size, capacity and tokens
*/

void			print_lexer(t_lexer *lexer);

#endif
