all: mmind test_gen_codes

mmind: mmind.c model.c utils.c mmind.h
	gcc -o mmind -Wall mmind.c model.c utils.c


test_gen_codes: test_gen_codes.c model.c utils.c mmind.h
	gcc -o test_gen_codes -Wall test_gen_codes.c model.c utils.c

clean:
	rm -rf mmind test_gen_codes
