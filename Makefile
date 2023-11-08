# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 13:26:32 by vdenisse          #+#    #+#              #
#    Updated: 2023/11/08 12:08:11 by vdenisse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -O0  -I/usr/include -Imlx_linux

HEADERS := so_long.h

SRCS := main.c
TEST_SRC := test.c
SRC := src/master.c	src/map_segmenter.c	src/game_movement.c	src/loop.c src/cleanup2.c src/map_flood.c src/print_map_textures.c src/event_handle.c src/utils.c src/creation.c src/cleanup.c src/map_parse.c src/gln/get_next_line_utils.c src/gln/get_next_line.c src/map_check.c main.c 

OBJDIR := obj
SRC_OBJS := $(SRC:%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(OBJDIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(SRC_OBJS) $(OBJS)
	@make -C src/libft
	@$(CC) $(SRC_OBJS) $(OBJS) $(CFLAGS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Lsrc/libft -lft -o $(NAME)
	@echo "Compiled $@"

clean:
	@make clean -C src/libft
	rm -rf $(OBJDIR) $(NAME)

fclean:
	@rm -rf $(OBJDIR)
	@$(clean)
	@rm -rf $(NAME)
	@make fclean -C src/libft

re:
	@make fclean
	@make $(NAME)

.PHONY: all clean

