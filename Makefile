EXEC = ooduck-example

HEADERS = $(shell find -name "*.h")
SOURCES = $(wildcard src/*.c)
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -I include -c
LDFLAGS = -O2 -Wall

ifeq ($(DEBUG), 1)
	CFLAGS += -g
	LDFLAGS += -g
endif

.PHONY: all
all: $(EXEC)

.PHONY: clean
clean:
	@rm -vf $(EXEC) $(OBJECTS)

$(EXEC): $(OBJECTS)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.c $(HEADERS)
	@mkdir -p obj
	$(CC) $(CFLAGS) $< -o $@
