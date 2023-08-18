TARGET = get_next_line

CC = cc

CFLAGS = -Wall -Wextra -Werror

RUN_CMD = ./$(TARGET)


SOURCES = main.c get_next_line.c get_next_line_utils.c
HEADER = get_next_line.h

all: $(TARGET)

$(TARGET): $(SOURCES) $(HEADER)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

run: $(TARGET)
	$(RUN_CMD)

clean:
	rm -f $(TARGET)