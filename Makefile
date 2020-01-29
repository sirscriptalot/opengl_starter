CFLAGS := -std=c17 -Wall

LDFLAGS := -lglew -lglfw -framework OpenGL

OBJS := $(patsubst %.h, %.o, $(wildcard *.h))

.PHONY: all clean run-main

all: main

clean:
	rm -f main
	rm -f *.o

main: main.c $(OBJS)
	cc $(CFLAGS) $(LDFLAGS) -o $@ $^

run-main: main
	./main

%.o: %.c %.h
	cc $(CFLAGS) -c $<