CC=gcc
FLAGS= -DDEBUG -W -Wall -g -O3
SRC= file.c free.c gestionnaire.c init.c input_output.c opcontact.c 
OBJ=$(SRC:%.c = obj/%.o)

Gestionnaire:	$(OBJ)
	@$(CC) $^ -o $@ $(FLAGS) 

obj/%.o:	%.c
	@$(CC) -c -o $@ $^ $(FLAGS) 

clean:	
	@rm -f *.o
	@rm -f *~
	@rm -f *#
	@rm -f Gestionnaire	
teste:	
	@./Gestionnaire

