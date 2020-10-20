NAME := ft_sh

SHELL = /bin/sh
RM = /bin/rm

.SUFFIXES:
.SUFFIXES: .c .o .h

# ************************************ LIBS ********************************** #

LIB			=	ft

# ********************************** INCLUDES ******************************** #

INC_FILES	=	ft_sh.h				\
				command.h			\
				lexer.h

# *********************************** C FILES ******************************** #

SRC_FILES	=	main.c				\
				lexer.c				\
				fill_lexer.c		\

# ********************************** OBJECTS ********************************* #

OBJ_FILES	=	$(SRC_FILES:%.c=%.o)

# ******************************** DIR AND PATHS ***************************** #

LIB_DIR		=	libft

INC_DIR		=	includes
SRC_DIR		=	src
OBJ_DIR		=	obj

SUB_DIRS	=	parsing

SRC_SUBDIRS	=	$(addprefix $(SRC_DIR)/, $(SUB_DIRS))

INC			=	$(addprefix $(INC_DIR)/, $(INC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

INC_PATHS	=	$(INC_DIR) $(addsuffix /$(INC_DIR), $(LIB_DIR))

VPATH		=	$(SRC_DIR) $(SRC_SUBDIRS)

# ******************************** CC AND FLAGS ****************************** #

CC = gcc

CFLAGS		=	-Wall -Wextra -Werror -g3
IFLAGS		=	$(foreach path, $(INC_PATHS), -I $(path))
LFLAGS		=	$(foreach dir, $(LIB_DIR), -L $(dir)) \
				$(foreach lib, $(LIB), -l $(lib))

# ********************************** RULES *********************************** #

all: $(NAME)

# INSTALL #

install :
	@$(foreach lib, $(LIB_DIR), make -C $(lib);)

re-install :
	@$(foreach lib, $(LIB_DIR), make -C $(lib) fclean;)
	@make install

# OBJ DIR #

$(OBJ_DIR):
	@mkdir -p $@
	@echo "Created\t\t$@ directory"

# COMPILING #

$(OBJ_DIR)/%.o : %.c
	@echo "\r\033[KCompiling\t$< \c"
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJ) $(INC)
	@$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $@
	@echo "\nOK\t\t$(NAME) is ready"

# DEBUG #

show:
	@echo "VPATH: $(VPATH)"

debug: CFLAGS+=-fsanitize=address
debug: re

# CLEAN #

clean:
	@$(foreach lib, $(LIB_DIR), make -C $(lib) clean;)
	@$(RM) -rf $(OBJ_DIR)
	@echo "Cleaned\t\tobject files"

fclean: clean
	@$(RM) $(NAME)
	@echo "Removed\t\t$(NAME)"

re: fclean all

.PHONY: all install re-install show debug clean fclean re
