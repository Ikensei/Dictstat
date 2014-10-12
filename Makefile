COMPILER = gcc
CCFLAGS = -ansi -pedantic -Wall -g
AR = ar

all: dictstat

dictstat: dictstat.o libtrie.a
	$(COMPILER) $(CCFLAGS) dictstat.o libtrie.a -o dictstat

libtrie.a: trie.o
	$(AR) -r libtrie.a trie.o

trie.o: trie.c
	$(COMPILER) $(CCFLAGS) -c trie.c

dictstat.o: dictstat.c
	$(COMPILER) $(CCFLAGS) -c dictstat.c

clean:
	rm -f *.o *.a *.gch dictstat
