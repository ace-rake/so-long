# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdenisse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/10 13:26:32 by vdenisse          #+#    #+#              #
#    Updated: 2023/11/06 11:20:43 by vdenisse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -O0  -I/usr/include -Imlx_linux #-fsanitize=address

HEADERS := so_long.h

SRCS := main.c
TEST_SRC := test.c
SRC := $(wildcard src/*.c)
GNL := $(wildcard src/gln/*.c)

OBJDIR := obj
OBJS :=  $(SRCS:%.c=$(OBJDIR)/%.o)
SRC_OBJS := $(SRC:%.c=$(OBJDIR)/%.o)
GNL_OBJS := $(GNL:%.c=$(OBJDIR)/%.o)
TEST_OBJS := $(TEST_SRC:%.c=$(OBJDIR)/%.o)

NEC_OBJS = $(SRC_OBJS) $(GNL_OBJS)

all: $(NAME)

$(OBJDIR)/%.o: %.c $(HEADERS)
	@mkdir -p $(@D)
	@echo "Compiling $<"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(NEC_OBJS) $(OBJS)
	@make -C src/libft
	@$(CC) $(NEC_OBJS) $(OBJS) $(CFLAGS) -pthread -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Lsrc/libft -lft -o $(NAME)
	@echo "Compiled $@"

test: $(NEC_OBJS) $(TEST_OBJS)
	@make -C src/libft
	$(CC) $(NEC_OBJS) $(TEST_OBJS) $(CFLAGS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -Lsrc/libft -lft -o test

clean:
	rm -rf $(OBJDIR) $(NAME)
#	@make clean -C src/libft

fclean:
	@rm -rf $(OBJDIR)
	@$(clean)
	@rm $(NAME)
#	@make fclean -C src/libft

re:
	@make fclean
	@make $(NAME)

.PHONY: all clean

