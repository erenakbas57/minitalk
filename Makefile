SERVER	= server


CLIENT	= client


CFLAGS	= -Wall -Wextra -Werror


all:	$(SERVER) $(CLIENT)

$(SERVER): 
	gcc $(CFLAGS) server.c -o $(SERVER)

$(CLIENT): 
	gcc $(CFLAGS) client.c -o $(CLIENT)

fclean: 
	rm -rf $(SERVER)
	rm -rf $(CLIENT)

re:	fclean all

.PHONY	: all clean re server.o client.o