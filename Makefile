include Make.include

OUTLIB = ./MT_random.a

all: $(OUTLIB)

$(OUTLIB): MT_random.o
	ar rvcs $@ $^

MT_random.o: MT_random.c MT_random.h
	$(CC) $(CCFLAGS) $(CCWFLAGS) -c $<

.PHONY: clean distclean

clean:
	rm -f *.o

distclean: clean
	rm -f $(OUTLIB)
