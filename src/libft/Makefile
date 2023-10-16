CC = cc
AR = ar
CFLAGS = -Wall -Werror -Wextra
ARFLAGS = rcs

NAME = libft.a
HEADERS :=	header/libft.h 

SRC :=		src/ft_atoi.c\
			src/ft_bzero.c\
			src/ft_calloc.c\
			src/ft_isalnum.c\
			src/ft_isalpha.c\
			src/ft_isascii.c\
			src/ft_isdigit.c\
			src/ft_isprint.c\
			src/ft_memchr.c\
			src/ft_memcmp.c\
			src/ft_memcpy.c\
			src/ft_memmove.c\
			src/ft_memset.c\
			src/ft_strchr.c\
			src/ft_strdup.c\
			src/ft_strjoin.c\
			src/ft_strlcat.c\
			src/ft_strlcpy.c\
			src/ft_strlen.c\
			src/ft_strncmp.c\
			src/ft_strnstr.c\
			src/ft_strrchr.c\
			src/ft_strtrim.c\
			src/ft_substr.c\
			src/ft_tolower.c\
			src/ft_toupper.c\
			src/ft_split.c\
			src/ft_itoa.c\
			src/ft_strmapi.c\
			src/ft_striteri.c\
			src/ft_putchar_fd.c\
			src/ft_putstr_fd.c\
			src/ft_putendl_fd.c\
			src/ft_putnbr_fd.c

SRCB =		src/ft_lstnew.c\
			src/ft_lstadd_front.c\
			src/ft_lstsize.c\
			src/ft_lstlast.c\
			src/ft_lstadd_back.c\
			src/ft_lstclear.c\
			src/ft_lstdelone.c\
			src/ft_lstiter.c\
			src/ft_lstmap.c\
			$(SRCS)

OBJDIR:=	obj
OBJ :=		$(SRC:%.c=$(OBJDIR)/%.o)
OBJB =		$(SRCB:%.c=$(OBJDIR)/%.o)

all:		$(NAME)

$(NAME):	$(OBJ) $(HEADERS)
				@$(AR) $(ARFLAGS) $(NAME) $^
				@echo "compiling $@"

$(OBJDIR)/%.o: %.c $(HEADERS)
				@mkdir -p $(@D) 
				@$(CC) $(CFLAGS) -c $< -o $@
				@echo "compiling $@"

clean:
				@rm -rf $(OBJDIR)
				@echo "removing objects from $(NAME)"

fclean: 	clean
				@rm -f $(NAME)
				@echo "removing $(NAME)"

re: fclean all

bonus: $(OBJB)
	$(AR) $(ARFLAGS) $(NAME) $^

.PHONY: all clean fclean re
