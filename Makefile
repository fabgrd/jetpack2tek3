##
## EPITECH PROJECT, 2021
## B-NWP-400-LYN-4-1-myteams-jessica.ebely
## File description:
## Makefile
##

SERVER		=	server/
CLIENT		=	client/

all: client server

client:
	@ make -C $(CLIENT) -s

server:
	@ make -C $(SERVER) -s

clean:
	@ make clean -C $(SERVER) -s
	@ make clean -C $(CLIENT) -s

fclean:
	@ make fclean -C $(CLIENT) -s
	@ make fclean -C $(SERVER) -s

re:
	@ make re -C $(SERVER) -s
	@ make re -C $(CLIENT) -s

.PHONY: all server client clean fclean re