# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 13:26:32 by vdenisse          #+#    #+#              #
#    Updated: 2023/11/21 12:58:31 by vdenisse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -O0  -I/usr/include -Imlx_linux

HEADERS := so_long.h

UP = \033[A                        
CLEAR = \e[2K
CLEAR_TILL_END = \e[0K
           
           
SET_BOLD_MODE = \e[1m
SET_DIM_MODE = \e[2m
SET_ITALIC_MODE = \e[3m
SET_UNDERLINE_MODE = \e[4m
SET_BLINKING_MODE = \e[5m
SET_INVERSE_MODE = \e[7m
SET_HIDDEN_MODE = \e[8m
SET_STRIKETHROUGH_MODE = \e[9m
           
RESET_BOLD_MODE = \e[22m
RESET_DIM_MODE = \e[22m
RESET_ITALIC_MODE = \e[23m
RESET_UNDERLINE_MODE = \e[24m
RESET_BLINKING_MODE = \e[25m
RESET_INVERSE_MODE = \e[27m
RESET_HIDDEN_MODE = \e[28m
RESET_STRIKETHROUGH_MODE = \e[29m
RESET_ALL = \e[0m
           
BLACK_BACK = \e[100m
RED_BACK = \e[101m
GREEN_BACK = \e[102m
YELLOW_BACK = \e[103m
BLUE_BACK = \e[104m
MAGENTA_BACK = \e[105m
CYAN_BACK = \e[106m
WHITE_BACK = \e[107m
RED = \e[91m
GREEN = \e[92m
YELLOW = \e[93m
BLUE = \e[94m
MAGENTA = \e[95m
CYAN = \e[96m
WHITE = \e[97m
	
define CREATION_ART
$(RED)+==============================================+
|$(GREEN) ____   ___     _     ___  _   _  ____        $(RED)|
|$(GREEN)/ ___| / _ \   | |   / _ \| \ | |/ ___|       $(RED)|
|$(GREEN)\___ \| | | |  | |  | | | |  \| | |  _        $(RED)|
|$(GREEN) ___) | |_| |  | |__| |_| | |\  | |_| |       $(RED)|
|$(GREEN)|____/ \___/___|_____\___/|_| \_|\____|       $(RED)|
|$(GREEN)  ____ ___|_____|_ ____ ___ _     _____ ____  $(RED)|
|$(GREEN) / ___/ _ \|  \/  |  _ \_ _| |   | ____|  _ \ $(RED)|
|$(GREEN)| |  | | | | |\/| | |_) | || |   |  _| | | | |$(RED)|
|$(GREEN)| |__| |_| | |  | |  __/| || |___| |___| |_| |$(RED)|
|$(GREEN) \____\___/|_|  |_|_|  |___|_____|_____|____/ $(RED)|
+==============================================+$(WHITE)
endef
export CREATION_ART

define UP_TO_DATE_ART
$(RED)+=========================================================================+
|$(GREEN) ____   ___     _     ___  _   _  ____   ___ ____                        $(RED)|
|$(GREEN)/ ___| / _ \   | |   / _ \| \ | |/ ___| |_ _/ ___|                       $(RED)|
|$(GREEN)\___ \| | | |  | |  | | | |  \| | |  _   | |\___ \                       $(RED)|
|$(GREEN) ___) | |_| |  | |__| |_| | |\  | |_| |  | | ___) |                      $(RED)|
|$(GREEN)|____/ \___/___|_____\___/|_| \_|\____| |___|____/                       $(RED)|
|$(GREEN)    _    _|_____|__  _____    _    ______   __  _   _ ____    _____ ___  $(RED)|
|$(GREEN)   / \  | |   |  _ \| ____|  / \  |  _ \ \ / / | | | |  _ \  |_   _/ _ \ $(RED)|
|$(GREEN)  / _ \ | |   | |_) |  _|   / _ \ | | | \ V /  | | | | |_) |   | || | | |$(RED)|
|$(GREEN) / ___ \| |___|  _ <| |___ / ___ \| |_| || |   | |_| |  __/    | || |_| |$(RED)|
|$(GREEN)/_/__ \_\_____|_| \_\_____/_/   \_\____/ |_|    \___/|_|       |_| \___/ $(RED)|
|$(GREEN)|  _ \  / \|_   _| ____|                                                 $(RED)|
|$(GREEN)| | | |/ _ \ | | |  _|                                                   $(RED)|
|$(GREEN)| |_| / ___ \| | | |___                                                  $(RED)|
|$(GREEN)|____/_/   \_\_| |_____|                                                 $(RED)|
+=========================================================================+$(WHITE)
endef
export UP_TO_DATE_ART

SRCS := main.c
TEST_SRC := test.c
SRC := src/master.c	src/map_segmenter.c	src/game_movement.c	src/loop.c src/cleanup2.c src/map_flood.c src/print_map_textures.c src/event_handle.c src/utils.c src/creation.c src/cleanup.c src/map_parse.c src/gln/get_next_line_utils.c src/gln/get_next_line.c src/gln/utils2.c src/map_check.c main.c 

TOTAL_TASKS:= $(words $(SRC))
CURRENT_TASK:= 0          
PROGRESS_FILE:= .progress

OBJDIR := obj
SRC_OBJS := $(SRC:%.c=$(OBJDIR)/%.o)

all:
	(make -q $(NAME) && echo "$$UP_TO_DATE_ART") || (make  build)

build:
	make pre_build
	make $(NAME)
	make post_build

$(OBJDIR)/%.o: %.c $(HEADERS)
	$(MAKE) update-progress
	mkdir -p $(@D)
	echo "\t$(CLEAR_TILL_END)Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@
	printf "$(CLEAR)$(UP)"

$(NAME): $(SRC_OBJS) $(OBJS)
	$(CC) $(SRC_OBJS) $(OBJS) $(CFLAGS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Lsrc/libft -lft -o $(NAME)

clean:
	make clean -C src/libft
	rm -rf $(OBJDIR)
	printf "$(YELLOW)Removed object files.$(WHITE)\n"

fclean:	clean
	rm -rf $(NAME)
	printf "$(YELLOW)Removed $(NAME).$(WHITE)\n"
	make fclean -C src/libft

re: fclean build

progress-bar:                                                  
	$(eval CURRENT_TASK=$(shell cat $(PROGRESS_FILE)))
	printf "\r["
	for i in $(shell seq 1 $(CURRENT_TASK)); do \
		printf "=";	\
	done
	for i in $(shell seq $(CURRENT_TASK) $(TOTAL_TASKS)); do \
	    printf " "; \
	done
	printf "]"
	printf " ($(CURRENT_TASK)/$(TOTAL_TASKS))"
                                                               
update-progress:                                               
	$(shell touch $(PROGRESS_FILE))                            
	$(eval CURRENT_TASK=$(shell cat $(PROGRESS_FILE)))         
	$(eval CURRENT_TASK=$(shell echo $$(($(CURRENT_TASK)+1)))) 
	echo "$(CURRENT_TASK)" > $(PROGRESS_FILE)                  
	$(MAKE) progress-bar                                       

pre_build:
	make -C src/libft
	echo "$(GREEN)$(SET_BLINKING_MODE)Compiling $(NAME)$(WHITE)"
	echo "0" > $(PROGRESS_FILE)

post_build:
	printf "$$CREATION_ART"
	$(shell rm -rf $(PROGRESS_FILE))


.PHONY: all clean
.SILENT:
