NAME = libftprintf.a

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Source files
SRC = ft_printf.c \
		ft_putchar.c \
		ft_puthexa.c \
		ft_putnbr.c \
		ft_putnbr_unsigned.c \
		ft_putptr.c \
		ft_putstr.c \
		handle_conversion.c \
		handle_conversion_bis.c

# Converts source into objects
OBJECTS = $(SRC:.c=.o)

# Principal rule
all: $(NAME)

# Compile .c into .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Create the printf library
$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

# Clean object files
clean:
	rm -f $(OBJECTS)

# Clean all (objects + library)
fclean: clean
	rm -f $(NAME)

# Recompile
re: fclean all

# Phony
.PHONY: all clean fclean re
