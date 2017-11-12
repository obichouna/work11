all: parse_args.c
	gcc -o hw11 parse_args.c
clean:
	rm *~
	rm a.out
run: all
	./hw11
