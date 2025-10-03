# =============================================
# 1. Base config
# =============================================
NAME_MANDATORY = client server
NAME_BONUS     = client_bonus server_bonus
CC             = cc
CFLAGS         = -Wall -Wextra -Werror
LIBFT_DIR      = libft
LIBFT_LIB      = $(LIBFT_DIR)/libft.a
FT_PRINTF_LIB  = $(LIBFT_DIR)/ft_printf/libftprintf.a
INCLUDES       = -Iincludes -I$(LIBFT_DIR) -I$(LIBFT_DIR)/ft_printf

# =============================================
# 2. Sources - MANDATORY
# =============================================
SRC_MANDATORY = srcs/mandatory/client.c \
				srcs/mandatory/server.c
OBJECTS_MANDATORY = $(SRC_MANDATORY:.c=.o)

# =============================================
# 3. Sources - BONUS
# =============================================
SRC_BONUS = srcs/bonus/client_bonus.c \
			srcs/bonus/server_bonus.c
OBJECTS_BONUS = $(SRC_BONUS:.c=.o)

# =============================================
# 4. Main rules
# =============================================
all: mandatory

mandatory: $(NAME_MANDATORY)

bonus: $(NAME_BONUS)

$(LIBFT_LIB):
	@echo "$(BLUE)🛠️ Compiling libft...$(RESET)"
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF_LIB):
	@echo "$(BLUE)🖨️ Compiling ft_printf...$(RESET)"
	$(MAKE) -C $(LIBFT_DIR)/ft_printf

# --- Mandatory compilation ---
client: srcs/mandatory/client.o $(LIBFT_LIB) $(FT_PRINTF_LIB)
	@echo "$(PURPLE)📝 Compiling client...$(RESET)"
	$(CC) $(CFLAGS) $(INCLUDES) -o client srcs/mandatory/client.o -L$(LIBFT_DIR) -lft -L$(LIBFT_DIR)/ft_printf -lftprintf
	@echo "$(GREEN)✅ client compiled successfully!$(RESET)"

server: srcs/mandatory/server.o $(LIBFT_LIB) $(FT_PRINTF_LIB)
	@echo "$(PURPLE)📝 Compiling server...$(RESET)"
	$(CC) $(CFLAGS) $(INCLUDES) -o server srcs/mandatory/server.o -L$(LIBFT_DIR) -lft -L$(LIBFT_DIR)/ft_printf -lftprintf
	@echo "$(GREEN)✅ server compiled successfully!$(RESET)"

# --- Bonus compilation ---
client_bonus: srcs/bonus/client_bonus.o $(LIBFT_LIB) $(FT_PRINTF_LIB)
	@echo "$(PURPLE)📝 Compiling client_bonus...$(RESET)"
	$(CC) $(CFLAGS) $(INCLUDES) -o client_bonus srcs/bonus/client_bonus.o -L$(LIBFT_DIR) -lft -L$(LIBFT_DIR)/ft_printf -lftprintf
	@echo "$(GREEN)✅ client_bonus compiled successfully!$(RESET)"

server_bonus: srcs/bonus/server_bonus.o $(LIBFT_LIB) $(FT_PRINTF_LIB)
	@echo "$(PURPLE)📝 Compiling server_bonus...$(RESET)"
	$(CC) $(CFLAGS) $(INCLUDES) -o server_bonus srcs/bonus/server_bonus.o -L$(LIBFT_DIR) -lft -L$(LIBFT_DIR)/ft_printf -lftprintf
	@echo "$(GREEN)✅ server_bonus compiled successfully!$(RESET)"

# --- Compilation des .o ---
srcs/mandatory/%.o: srcs/mandatory/%.c $(LIBFT_LIB) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

srcs/bonus/%.o: srcs/bonus/%.c $(LIBFT_LIB) $(FT_PRINTF_LIB)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# =============================================
# 5. Cleaning
# =============================================
clean:
	@echo "$(YELLOW)🧹 Cleaning object files...$(RESET)"
	rm -f $(OBJECTS_MANDATORY) $(OBJECTS_BONUS)
	$(MAKE) -C $(LIBFT_DIR) clean > /dev/null 2>&1
	$(MAKE) -C $(LIBFT_DIR)/ft_printf clean > /dev/null 2>&1
	@echo "$(GREEN)✅ Clean completed!$(RESET)"

fclean: clean
	@echo "$(RED)🧹 Deep cleaning (executables + objects)...$(RESET)"
	rm -f $(NAME_MANDATORY) $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null 2>&1
	$(MAKE) -C $(LIBFT_DIR)/ft_printf fclean > /dev/null 2>&1

re: fclean all
	@echo "$(GREEN)✅ Full recompilation done!$(RESET)"

# =============================================
# 6. Help
# =============================================
help:
	@echo "$(BLUE)📜 Available targets:$(RESET)"
	@echo "  $(GREEN)all$(RESET)          : Compile mandatory only"
	@echo "  $(YELLOW)bonus$(RESET)       : Compile only bonus part"
	@echo "  $(RED)clean$(RESET)        : Remove object files"
	@echo "  $(RED)fclean$(RESET)       : Remove all generated files"
	@echo "  $(GREEN)re$(RESET)          : Full recompilation"
	@echo "  $(PURPLE)help$(RESET)        : Show this help"

# =============================================
# 7. Special rules
# =============================================
.PHONY: all mandatory bonus clean fclean re help client server client_bonus server_bonus
