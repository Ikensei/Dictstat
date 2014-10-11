COMPILER = gcc
CCFLAGS = -ansi -pedantic -Wall -g
AR = ar

all: dictstat

dictstat: dictstat.o libtrie.a
  $(COMPILER) $(CCFLAGS) dictstat.o libtrie.a -o dictstat

libtrie.a: trie.o
  $(AR) -r libtrie.a trie.o

trie.o:
  $(COMPILER) $(CCFLAGS) -c trie.c trie.h

dictstat.o:
  $(COMPILER) $(CCFLAGS) -c dictstat.c dictstat.h

clean:
  rm *.o *.a *.gch dictstat
