CFLAGS += -Wall \
	  -Werror \
	  -pedantic \
	  --std=c99 \
	  -pthread

all: main.out test

main.out: main.c
	@gcc main.c -o $@ $(CFLAGS) 
	@echo "Compilation successful!"

test: main.out
	@echo "Running main.out..."
	@./main.out

clean:
	@rm -f main.out
	@echo "Cleaned successfully!"
