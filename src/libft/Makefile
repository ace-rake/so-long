CC = cc
AR = ar
CFLAGS = -Wall -Werror -Wextra
ARFLAGS = -rcs

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
			src/ft_putnbr_fd.c\
			src/ft_free_array.c\
			src/ft_strform.c\
			src/ft_realloc.c\
			src/ft_lalloc.c\
			src/ft_lstnew.c\
			src/ft_lstadd_front.c\
			src/ft_lstsize.c\
			src/ft_lstlast.c\
			src/ft_lstadd_back.c\
			src/ft_lstclear.c\
			src/ft_lstdelone.c\
			src/ft_lstiter.c\
			src/ft_lstmap.c\

TOTAL_TASKS:= $(words $(SRC))
CURRENT_TASK:= 0
PROGRESS_FILE:= .progress

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

define HEADER
$(GREEN)___________              __
$(RED)\__    ___/___   _______/  |_
$(GREEN)  |    |_/ __ \ /  ___/\   __\\
$(RED)  |    |\  ___/ \___ \  |  |
$(GREEN)  |____| \___  >____  > |__|
$(RED)             \/     \/
endef
export HEADER

define CREATION_ART
$(RED)+================================================================+
|$(GREEN) _     ___ ____  _____ _____    _                               $(RED)|
|$(GREEN)| |   |_ _| __ )|  ___|_   _|  / \                              $(RED)|
|$(GREEN)| |    | ||  _ \| |_    | |   / _ \                             $(RED)|
|$(GREEN)| |___ | || |_) |  _|   | |_ / ___ \                            $(RED)|
|$(GREEN)|_____|___|____/|_|   _ |_(_)_/___\_\____                       $(RED)|
|$(GREEN) / ___|  _ \| ____|  / \|_   _| ____|  _ \                      $(RED)|
|$(GREEN)| |   | |_) |  _|   / _ \ | | |  _| | | | |                     $(RED)|
|$(GREEN)| |___|  _ <| |___ / ___ \| | | |___| |_| |                     $(RED)|
|$(GREEN) \____|_| \_\_____/_/__ \_\_| |_____|____/_   _ _     _  __   __$(RED)|
|$(GREEN)/ ___|| | | |/ ___/ ___| ____/ ___||  ___| | | | |   | | \ \ / /$(RED)|
|$(GREEN)\___ \| | | | |  | |   |  _| \___ \| |_  | | | | |   | |  \ V / $(RED)|
|$(GREEN) ___) | |_| | |__| |___| |___ ___) |  _| | |_| | |___| |___| |  $(RED)|
|$(GREEN)|____/ \___/ \____\____|_____|____/|_|    \___/|_____|_____|_|  $(RED)|
+================================================================+$(WHITE)
endef
export CREATION_ART

define UP_TO_DATE_ART
$(RED)+=========================================================================+
|$(GREEN) _     ___ ____  _____ _____    _      ___ ____                          $(RED)|
|$(GREEN)| |   |_ _| __ )|  ___|_   _|  / \    |_ _/ ___|                         $(RED)|
|$(GREEN)| |    | ||  _ \| |_    | |   / _ \    | |\___ \                         $(RED)|
|$(GREEN)| |___ | || |_) |  _|   | |_ / ___ \   | | ___) |                        $(RED)|
|$(GREEN)|_____|___|____/|_|  ___|_(_)_/   \_\_|___|____/_   _ ____    _____ ___  $(RED)|
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

RESET_SCREEN = \e[2J


OBJDIR:=	obj
OBJ :=		$(SRC:%.c=$(OBJDIR)/%.o)
OBJB :=		$(SRCB:%.c=$(OBJDIR)/%.o)

all:
	(make -q $(NAME) && echo "$$UP_TO_DATE_ART") || (make  build)



build:			
	make pre_build 
	make $(NAME)
	make post_build


$(NAME):	$(OBJ) $(HEADERS)
				$(AR) $(ARFLAGS) $(NAME) $^


$(OBJDIR)/%.o: %.c $(HEADERS)
				$(MAKE) update-progress
				mkdir -p $(@D) 
				$(CC) $(CFLAGS) -c $< -o $@
				echo  "\t$(CLEAR_TILL_END)compiling $@"
				printf "$(CLEAR)$(UP)"


clean:
				rm -rf $(OBJDIR)
				rm -f $(PROGRESS_FILE)
				echo "$(YELLOW)removed objects from $(NAME)$(WHITE)"


fclean: 	
				make clean
				rm -f $(NAME)
				echo "$(YELLOW)removed $(NAME)$(WHITE)"

t: 
	echo "$$CREATION_ART"


re: fclean all

progress-bar:
	$(eval CURRENT_TASK=$(shell cat $(PROGRESS_FILE)))
	printf "["
	for i in $(shell seq 1 $(CURRENT_TASK)); do \
        printf "="; \
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
	echo "$(GREEN)$(SET_BLINKING_MODE)Compiling libft.a$(WHITE)"
	echo "0" > $(PROGRESS_FILE)

post_build:
	echo "$(CLEAR)$$CREATION_ART"
	$(shell rm -rf $(PROGRESS_FILE))

	
test:		$(OBJ) $(OBJB) $(HEADERS)
				echo "compiling test"
				$(CC) $(CFLAGS) $(OBJ) $(OBJB) -o $@
				echo "running test"
				./$@


.SILENT:
.PHONY: all clean fclean re test progress-bar update-progress .progress
