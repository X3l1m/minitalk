####################################
SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)
####################################
CC = gcc
CFLAGS = -Wall -Wextra -Werror
####################################
all: server client

bonus: server client

server: server.o libft
	@echo Server  creating...
	@$(CC) -o $@ $< -Llibft -lft

client: client.o libft
	@echo Client creating...
	@$(CC) -o $@ $< -Llibft -lft

%.o: %.c
	@$(CC) -c $(CFLAGS) $?

libft:
	@echo Libft creating...
	@make -C libft

clean:
	@echo Cleaning objects...
	@rm -f $(OBJECTS)
	@make -C libft clean
	
fclean: clean
	@rm -f server client libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re

# Siyah: \033[0;30m veya \033[30m
# Kırmızı: \033[0;31m veya \033[31m
# Yeşil: \033[0;32m veya \033[32m
# Sarı: \033[0;33m veya \033[33m
# Mavi: \033[0;34m veya \033[34m
# Magenta: \033[0;35m veya \033[35m
# Cyan: \033[0;36m veya \033[36m
# Beyaz: \033[0;37m veya \033[37m
# Bold: \033[1m
# Altı çizili: \033[4m
# Ters: \033[7m
# Sıfırlama: \033[0m