NAME := ft_sh

SHELL = /bin/sh
RM = /bin/rm

.SUFFIXES:
.SUFFIXES: .c .o .h

# ********************************* INCLUDES ********************************* #

INC_FILES	=	ft_sh.h				\
				command.h			\
				lexer.h

# ********************************* C FILES ********************************** #

SRC_FILES	=	main.c				\
				lexer.c				\
				fill_lexer.c		\

# ********************************* OBJECTS ********************************** #

OBJ_FILES	=	$(SRC_FILES:%.c=%.o)

# *********************************** LIBS *********************************** #

LIBS		=	ft

# ****************************** DIRS AND PATHS ****************************** #

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

# *************************** COMPILING AND FLAGS **************************** #

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror -g3
CPPFLAGS	=	$(foreach path, $(INC_PATHS), -I $(path))
LDFLAGS		=	$(foreach dir, $(LIB_DIR), -L $(dir))
LDLIBS		=	$(foreach lib, $(LIBS), -l $(lib))

# ********************************** RULES *********************************** #

all: $(NAME)

# INSTALL #

install :
	@make -C $(LIB_DIR)

re-install :
	@make -C $(LIB_DIR) fclean
	@make install

# OBJ DIR #

$(OBJ_DIR):
	@mkdir -p $@
	@echo "Created\t\t$@ directory"

# COMPILING #

$(OBJ_DIR)/%.o : %.c
	@echo "\r\033[KCompiling\t$< \c"
	@$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ_DIR) $(OBJ) $(INC)
	@$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) $(LDLIBS) -o $@
	@echo "\nOK\t\t$(NAME) is ready"

# DEBUG #

show:
	@echo "VPATH: $(VPATH)"

debug: CFLAGS += -fsanitize=address
debug: re

# CLEAN #

clean:
	@make -C $(LIB_DIR) clean
	@$(RM) -rf $(OBJ_DIR)
	@echo "Cleaned\t\tobject files"

fclean: clean
	@$(RM) -f $(NAME)
	@echo "Removed\t\t$(NAME)"

re: fclean all

.PHONY: all install re-install show debug clean fclean re
