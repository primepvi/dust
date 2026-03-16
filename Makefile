CC = clang
CFLAGS = -Wall -g -Iinclude -lm

SRCS = $(shell find src -name "*.c")
OBJS = $(patsubst src/%.c, build/%.o, $(SRCS))
BIN = dust

.PHONY: clean compile

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

build/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build $(BIN)

compile:
	make clean && bear -- make
