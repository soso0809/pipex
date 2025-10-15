# =============================================================================
# Makefile pour Pipex (42) - Avec libft et ft_printf
# =============================================================================

# --- Couleurs (optionnel mais utile) ---
BLUE	= \033[1;34m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
RED		= \033[1;31m
RESET	= \033[0m

# --- Config de base ---
NAME_MANDATORY	= pipex
NAME_BONUS		= pipex_bonus
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
LIBFT_DIR		= libft
LIBFT_LIB		= $(LIBFT_DIR)/libft.a
FT_PRINTF_LIB	= $(LIBFT_DIR)/ft_printf/libftprintf.a
INCLUDES		= -Iincludes -I$(LIBFT_DIR) -I$(LIBFT_DIR)/ft_printf

# --- Sources (à adapter selon ton organisation) ---
SRC_MANDATORY	= srcs/main.c \
				  srcs/utils/errors.c \
				  srcs/parsing/parse.c \
				  srcs/parsing/parse_utils.c \
				  srcs/execution/exec.c \
				  srcs/execution/paths.c \
				  srcs/execution/paths_utils.c

OBJECTS_MANDATORY = $(SRC_MANDATORY:.c=.o)

SRC_BONUS		= srcs/bonus/main_bonus.c \
				  srcs/bonus/here_doc.c \
				  srcs/bonus/parse_bonus.c \
				  srcs/bonus/parse_utils_bonus.c \
				  srcs/bonus/free_bonus.c \
				  srcs/bonus/exec_utils_bonus.c \
				  srcs/utils/errors.c \
				  srcs/parsing/parse.c \
				  srcs/parsing/parse_utils.c \
				  srcs/bonus/exec_bonus.c \
				  srcs/execution/paths.c \
				  srcs/execution/paths_utils.c

OBJECTS_BONUS	= $(SRC_BONUS:.c=.o)

# =============================================================================
# Règles principales
# =============================================================================
all: mandatory

mandatory: $(NAME_MANDATORY)

bonus: $(NAME_BONUS)

# --- Compilation des libs (libft et ft_printf) ---
$(LIBFT_LIB):
	@echo "$(BLUE)🛠️ Compiling libft...$(RESET)"
	$(MAKE) -C $(LIBFT_DIR) > /dev/null

$(FT_PRINTF_LIB):
	@echo "$(BLUE)🖨️ Compiling ft_printf...$(RESET)"
	$(MAKE) -C $(LIBFT_DIR)/ft_printf > /dev/null

# --- Compilation de la partie obligatoire ---
$(NAME_MANDATORY): $(OBJECTS_MANDATORY) $(LIBFT_LIB) $(FT_PRINTF_LIB)
	@echo "$(PURPLE)🔧 Compiling $(NAME_MANDATORY)...$(RESET)"
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^ -L$(LIBFT_DIR) -lft -L$(LIBFT_DIR)/ft_printf -lftprintf
	@echo "$(GREEN)✅ $(NAME_MANDATORY) compiled successfully!$(RESET)"

# --- Compilation de la partie bonus ---
$(NAME_BONUS): $(OBJECTS_BONUS) $(LIBFT_LIB) $(FT_PRINTF_LIB)
	@echo "$(PURPLE)🔧 Compiling $(NAME_BONUS) (with bonus)...$(RESET)"
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(OBJECTS_BONUS) -L$(LIBFT_DIR) -lft -L$(LIBFT_DIR)/ft_printf -lftprintf
	@echo "$(GREEN)✅ $(NAME_BONUS) compiled successfully!$(RESET)"

# --- Compilation des fichiers .o ---
srcs/%.o: srcs/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

srcs/bonus/%.o: srcs/bonus/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# =============================================================================
# Nettoyage
# =============================================================================
clean:
	@echo "$(YELLOW)🧹 Cleaning object files...$(RESET)"
	rm -f $(OBJECTS_MANDATORY) $(OBJECTS_BONUS)
	$(MAKE) -C $(LIBFT_DIR) clean > /dev/null 2>&1
	$(MAKE) -C $(LIBFT_DIR)/ft_printf clean > /dev/null 2>&1

fclean: clean
	@echo "$(RED)🧹 Deep cleaning (executables + objects)...$(RESET)"
	rm -f $(NAME_MANDATORY) $(NAME_BONUS)

re: fclean all

# =============================================================================
# Aide
# =============================================================================
help:
	@echo "$(BLUE)📜 Makefile Help for Pipex:$(RESET)"
	@echo "  $(GREEN)make$(RESET)          : Compile mandatory part"
	@echo "  $(GREEN)make bonus$(RESET)    : Compile with bonus (here_doc)"
	@echo "  $(YELLOW)make clean$(RESET)   : Remove object files"
	@echo "  $(RED)make fclean$(RESET)    : Remove all generated files"
	@echo "  $(PURPLE)make re$(RESET)      : Full recompilation"
	@echo "  $(BLUE)make help$(RESET)      : Show this help"

# =============================================================================
# Règles PHONY
# =============================================================================
.PHONY: all mandatory bonus clean fclean re help
