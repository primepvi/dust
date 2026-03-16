CC = clang
LFLAGS = -lm -lglfw -lGL -ldl
IFLAGS = -Iinclude -Iexternal/glad/include
CFLAGS = -Wall -g $(IFLAGS)

SRCS = $(shell find src -name "*.c") external/glad/src/glad.c
OBJS = $(patsubst src/%.c, build/%.o, $(SRCS))

BIN = dust

.PHONY: clean compile

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

build/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf build $(BIN)

compile:
	make clean && bear -- make
