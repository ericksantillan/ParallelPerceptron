CFLAGS = -std=c99

all: perceptron
clean :
	rm *.o *~ perceptron

%.o : %.c
	gcc $(CFLAGS) -g -c $< -o $@


perceptron: perceptron.o utils.o
	gcc -g perceptron.o utils.o -o perceptron

test_func: test_func.o utils.o
	gcc -g test_func.o utils.o -o test_func
