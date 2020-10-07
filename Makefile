NAME := 21sh

SHELL = /bin/sh
RM = /bin/rm

.SUFFIXES:
.SUFFIXES: .c .o .h

# ******************************** CC AND FLAGS ****************************** #

CC = gcc

CFLAGS		=	-Wall -Wextra -Werror
IFLAGS		=	$(foreach path, $(INC_PATHS), -I $(path))
LFLAGS		=	$(foreach dir, $(LIB_DIR), -L $(dir)) \
				$(foreach lib, $(LIB), -l $(lib))

# ******************************** DIR AND PATHS ***************************** #

LIB_DIR		=	libft

INC_DIR		=	includes
SRC_DIR		=	src
OBJ_DIR		=	obj

INC			=	$(addprefix $(INC_DIR)/, $(INC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:%.c=%.o))

INC_PATHS	=	$(INC_DIR) $(addsuffix /$(INC_DIR), $(LIB_DIR))

VPATH		=	$(SRC_DIR) $(LIB_DIR)

# *********************************** LIB ************************************ #

LIB			=	ft

# ********************************** FILES *********************************** #

INC_FILES	=	ft_sh.h				\
				command.h			\
				lexer.h

SRC			=	main.c				\
				lexer.c				\
				fill_lexer.c		\

# ********************************** RULES *********************************** #

.PHONY: all
all: $(NAME)

# INSTALL #

.PHONY: install
install :
	@$(foreach dir, $(LIB_DIR), make -C $(dir);)

.PHONY: re-install
re-install :
	@$(foreach dir, $(LIB_DIR), make -C $(dir) fclean;)
	@make install

$(NAME): $(OBJ_DIR) $(OBJ) $(INC)
	@$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $@
	@echo "\nOK\t\t$(NAME) is ready"

# OBJ DIR #

$(OBJ_DIR):
	@mkdir -p $@
	@echo "Created\t\t$@ directory"

# COMPILING #

$(OBJ_DIR)/%.o : %.c
	@echo "\r\033[KCompiling\t$< \c"
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

# DEBUG #

.PHONY: show
show:
	@echo "VPATH: $(VPATH)"

.PHONY: debug
debug: CFLAGS+=-g3 -fsanitize=address
debug: re

# CLEAN #

.PHONY: clean
clean:
	@$(foreach dir, $(LIB_DIR), make -C $(dir) clean;)
	@$(RM) -rf $(OBJ_DIR)
	@echo "Cleaned\t\tobject files"

.PHONY: fclean
fclean: clean
	@$(RM) $(NAME)
	@echo "Removed\t\t$(NAME)"

.PHONY: re
re: fclean all
