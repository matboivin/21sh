NAME := 21sh

SHELL = /bin/sh
RM = rm -rf

.SUFFIXE:
.SUFFIXES: .c .o .h

# ******************************** CC AND FLAGS ****************************** #

CC = gcc

CFLAGS	=	-Wall -Wextra -Werror
IFLAGS	=	$(foreach dir, $(INC_PATH), -I $(dir))
LFLAGS	=	$(foreach dir, $(LIB_PATH), -L $(dir)) \
			$(foreach lib, $(LIB), -l $(lib))

# ******************************** DIR AND PATHS ***************************** #

LIB_PATH	=	libft
INC_PATH	=	$(shell find includes -type d) libft/includes
SRC_PATH	=	$(shell find src -type d)
OBJ_PATH	=	obj

INC			=	$(addprefix includes/, $(INC_FILES))
OBJ			=	$(addprefix $(OBJ_PATH)/, $(SRC:%.c=%.o))

vpath %.c $(foreach dir, $(SRC_PATH), $(dir):)

# *********************************** LIB ************************************ #

LIB			=	ft

# ********************************** FILES *********************************** #

INC_FILES	=	sh.h

SRC			=	main.c

# ********************************** RULES *********************************** #

.PHONY: all
all: $(NAME)

# INSTALL #

.PHONY: install
install :
	@$(foreach dir, $(LIB_PATH), make -C $(dir);)

.PHONY: re-install
re-install :
	@make -C libft fclean
	@make install

$(NAME): $(OBJ_PATH) $(OBJ) $(INC)
	@$(CC) $(CFLAGS) $(OBJ) $(LFLAGS) -o $@
	@echo "\nOK\t\t$(NAME) is ready"

# OBJ DIR #

$(OBJ_PATH):
	@mkdir -p $@
	@echo "Created\t\t$@ directory"

# COMPILING #

$(OBJ_PATH)/%.o : %.c
	@echo "\r\033[KCompiling\t$< \c"
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

# DEBUG #

.PHONY: debug
debug: CFLAGS+=-g3 -fsanitize=address
debug: re

# CLEAN #

.PHONY: clean
clean:
	@make -C libft clean
	@$(RM) $(OBJ_PATH)
	@echo "Cleaned\t\tobject files"

.PHONY: fclean
fclean: clean
	@$(RM) $(NAME)
	@echo "Removed\t\t$(NAME)"

.PHONY: re
re: fclean all
