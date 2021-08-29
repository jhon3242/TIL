CFLAGS = -Wall -Wextra -Werror

TARGET = ft_tail
SOURCES = main.c
OBJECTS = $(SOURCES:.c =.o)

%.o : %.c
	gcc $(CFLAGS) -c $<

all : $(TARGET)


$(TARGET) :$(OBJECTS)
	gcc $(CFLAGS) $^ -o $@ 
	

clena : 
	rm -f $(OBJECTS)

fclean : clean
	rm -f $(TARGET)

