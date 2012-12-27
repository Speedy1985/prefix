EXECS = prefix

all: $(EXECS)

prefix: prefix.c
	mipsel-unknown-linux-gnu-cc -O2 prefix.c -lm -o prefix

clean:
	rm -f $(EXECS) *.o

