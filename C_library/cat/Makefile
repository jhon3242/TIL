CC = gcc
CFLAGS = -Wall -Wextra -Werror

TARGET = ft_cat
SOURCES = main.c
OBJECT = $(SOURCES:.c =.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $<


$(TARGET) : $(OBJECT)
	$(CC) $(CFLAGS) $^ -o $@

all : $(TARGET)

clean : 
	rm -f $(OBJECT)
fclean : clean
	rm -f $(TARGET)
re : fclean all 
