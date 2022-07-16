CFLAGS := 
NAME = push_swap
C_SOURCES := 	main.c\
				

all:$(NAME) 


$(NAME): $(OBJ)
	$(CC) $(C_SOURCES)  -Ofast -o $(NAME)

%.o: %.c
	$(CC)   -c $< -o $@

bonus:
	$(MAKE) WITH_BONUS=1 all

clean:
	rm -f $(C_SOURCES:.c=.o) $(BONUS_FILES:.c=.o)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: re  
	./push_swap

.PHONY := all clean fclean bonus re