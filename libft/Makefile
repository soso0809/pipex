NAME	= libft.a

CC		= cc
CFLAGS	= -Wall -Wextra -Werror -std=c99


SRC		= ft_isalpha.c \
		ft_isdigit.c \
		ft_strlen.c \
		ft_strclen.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_manhattan.c \
		ft_error.c

SRC_BONUS	= ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c

SRC_PRINTF	= ft_printf/ft_printf.c \
		ft_printf/ft_putchar.c \
		ft_printf/ft_puthexa.c \
		ft_printf/ft_putnbr.c \
		ft_printf/ft_putnbr_unsigned.c \
		ft_printf/ft_putptr.c \
		ft_printf/ft_putstr.c \
		ft_printf/handle_conversion.c \
		ft_printf/handle_conversion_bis.c

SRC_GNL		= get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c

OBJECTS			= $(SRC:.c=.o)
OBJECTS_BONUS	= $(SRC_BONUS:.c=.o)
OBJECTS_PRINTF	= $(SRC_PRINTF:.c=.o)
OBJECTS_GNL		= $(SRC_GNL:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) $(OBJECTS_PRINTF) $(OBJECTS_GNL)
	   ar rcs $(NAME) $(OBJECTS) $(OBJECTS_PRINTF) $(OBJECTS_GNL)

mandatory: $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

bonus: $(OBJECTS) $(OBJECTS_BONUS)
	ar rcs $(NAME) $(OBJECTS) $(OBJECTS_BONUS)

printf: $(OBJECTS) $(OBJECTS_PRINTF)
	ar rcs $(NAME) $(OBJECTS) $(OBJECTS_PRINTF)

full: $(OBJECTS) $(OBJECTS_BONUS) $(OBJECTS_PRINTF)
	ar rcs $(NAME) $(OBJECTS) $(OBJECTS_BONUS) $(OBJECTS_PRINTF)


# règle pour compiler les .o dans ft_printf/ et get_next_line/
%.o: %.c
	   $(CC) $(CFLAGS) -I. -c $< -o $@
ft_printf/%.o: ft_printf/%.c
	   $(CC) $(CFLAGS) -I. -c $< -o $@
get_next_line/%.o: get_next_line/%.c
	   $(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJECTS) $(OBJECTS_BONUS) $(OBJECTS_PRINTF) $(OBJECTS_GNL)
	rm -f libft.so

fclean: clean
	rm -f $(NAME)

re: fclean all

so:
	$(CC) -Wall -Wextra -Werror -fPIC -I. -c $(SRC) $(SRC_BONUS) $(SRC_PRINTF)
	$(CC) -shared -o libft.so $(OBJECTS) $(OBJECTS_BONUS) $(OBJECTS_PRINTF)

.PHONY: all mandatory bonus printf full clean fclean re so
