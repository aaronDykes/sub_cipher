CC	:= gcc
ARGS	:= -O2

cipher: main.c sub_cipher.o
	$(CC) -o $@ $^ $(ARGS)

%.o: %.c %.h
	$(CC) -c $< $(ARGS)

clean:
	rm *.o cipher
