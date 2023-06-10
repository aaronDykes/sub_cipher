CC	:= gcc
ARGS	:= -O2

cipher: main.c sub_cipher.o
	$(CC) -o $@ $^ $(ARGS)

sub_cipher.o: sub_cipher.c sub_cipher.h
	$(CC) -c $< $(ARGS)

clean:
	rm *.o cipher
