# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: seyildir <seyildir@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/04/06 14:27:59 by seyildir      #+#    #+#                  #
#    Updated: 2023/04/06 14:27:59 by seyildir      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SERVER   = server
CLIENT   = client
CC	     = gcc
FLAGS    = -Wall -Werror -Wextra
LIBS	 = -L./libft -lft
LIBFT	 = libft.a

all : $(LIBFT) $(SERVER) $(CLIENT)

$(LIBFT) : 
	@make -C libft

$(SERVER) : server.o
	@$(CC) server.o $(LIBS) -o $@
	@printf "\e[38;5;226m./$@ successfully build🥑\e[0m\n"

$(CLIENT) : client.o
	@$(CC) client.o $(LIBS) -o $@
	@printf "\e[38;5;46m./$@ successfully build🥝\e[0m\n"

%.o : %.c
	@$(CC) $(FLAGS) $< -c -I includes

clean :
	@make clean -C libft
	@rm -f *.o
	@printf "\e[38;5;206m objects files deleted🚽\e[0m\n"

fclean: clean
	@make fclean -C libft
	@rm -f $(SERVER) $(CLIENT)
	@printf "\e[38;5;200mBinaries deleted🗑\e[0m\n"

re: fclean all

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