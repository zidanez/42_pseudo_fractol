# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnancy <fnancy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/03 14:41:58 by fnancy            #+#    #+#              #
#    Updated: 2020/07/26 14:12:50 by fnancy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re, make_lft

# ************************************************************************** #
#                           colors                                           #
# ************************************************************************** #

RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PINK = \033[35m
AQUA = \033[36m
GREY = \033[37m
UNDERLINE = \033[4m
ESCN = \033[0m

# ************************************************************************** #
#                           Configuration                                    #
# ************************************************************************** #
NAME = fractol
FLAGS = -Wall -Wextra -Werror -W

WS_PATH = $(shell pwd)
SRC_PATH = $(WS_PATH)/srcs/
OBJ_PATH = $(WS_PATH)/objs/
INC_PATH = $(WS_PATH)/includes/
LIB_PATH = $(WS_PATH)/libft/
LIB_INC_PATH = $(LIB_PATH)includes/
LIB_MINILIB_PATH = $(WS_PATH)/minilibx/
FRAMEWORK = -framework OpenGL -framework AppKit

SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_FILES))
INC = $(addprefix -I, $(INC_PATH))
INC_LIB = $(addprefix -I, $(LIB_INC_PATH))

SRC_FILES = main.c julia.c fractol_init.c mondelbrode.c control.c burningship.c draw_fractal.c

ADD_OBJ = $(addprefix $(OBJ_PATH), env bltns exe lex readline bltns/bltn_cd sys_tool)


OBJ_FILES = $(SRC_FILES:.c=.o)

# ************************************************************************** #
#                                   Rules                                    #
# ************************************************************************** #

all: $(NAME)

$(NAME): $(OBJ)
	@make make_lft
	@gcc -o $(NAME) $(INC) $(INC_LIB) $(OBJ) -L $(LIB_MINILIB_PATH) -lmlx $(FRAMEWORK) -L $(LIB_PATH) -lft

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@echo "$(GREY)$(UNDERLINE)CREATING >> $@$(ESCN)"
	@mkdir -p $(OBJ_PATH)
	#@mkdir -p $(ADD_OBJ)
	@gcc $(INC) $(INC_LIB) -o $@ -c $<

make_lft:
	@echo "$(GREEN)$(UNDERLINE)COMPILING LIBFT$(ESCN)"
	@make -C $(LIB_PATH)

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LIB_PATH)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIB_PATH)

re: fclean all
