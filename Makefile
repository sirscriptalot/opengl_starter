CFLAGS := -std=c17 -Wall

LDFLAGS := -lglew -lglfw -framework OpenGL

.PHONY: all clean run-main

all: main

clean:
	rm -f main

main: main.c
	cc $(CFLAGS) $(LDFLAGS) -o $@ $^

run-main: main
	./main
