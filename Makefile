.PHONY: all doc clean dist

CC = gcc
OPATH = obj/
DOCGEN=doxygen
CPPFLAGS += -I include
CFLAGS += -Wall

TARNAME = AchrafChemaou-GoL-2_0.tar.xz

vpath %.c src/
vpath %.h include/

all : main

main : $(addprefix $(OPATH), main.o grille.o io.o jeu.o)
	$(CC) $(CFLAGS) -o $@ $^

$(OPATH)%.o : %.c | $(OPATH)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c -o $@ $<

$(OPATH):
	mkdir $@

docs :
	$(DOCGEN)

clean :
	$(RM) -r doc/ $(OPATH) main $(TARNAME)

dist :
	tar -jcvf $(TARNAME) src include README.md Makefile Doxyfile