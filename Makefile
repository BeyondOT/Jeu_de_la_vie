.PHONY: docs clean dist run

TARGET = JeuDeVie
TARNAME = AchrafChemaou-GoL-2_0.tar.xz

SRCDIR = src
OBJDIR = obj
BINDIR = bin
INCLUDIR = include
DOCGEN = doxygen
LIBDIR = lib

LCC= gcc -o
CC = gcc
FLAGS = -Wall `pkg-config --cflags cairo` -I/usr/include/X11 -lcairo -lX11 
LFLAGS = -Wall `pkg-config --cflags cairo` -I/usr/include/X11 -lcairo -lX11 

 
SOURCE = $(SRCDIR)/io.c $(SRCDIR)/main.c
LIBSRC = $(SRCDIR)/grille.c $(SRCDIR)/jeu.c
INCLUDE := $(wildcard $(INCLUDIR)/*.h)

ifeq ($(MODE),TEXTE)
	TEXTE = _mode_texte
	SOURCE = $(SRCDIR)/io_mode_texte.c $(SRCDIR)/main_mode_texte.c
endif

OBJECT := $(SOURCE:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

OBJECTS_SRC = io.o main.o
OBJECTS_LIB = $(LIBSRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
LIB = $(LIBDIR)/libjeu.a

$(BINDIR)/$(TARGET): $(OBJECT) $(LIB)
	mkdir -p $(BINDIR)
	@$(LCC) $@ $(OBJECT) $(LIB) $(LFLAGS)

$(OBJECT): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	@$(CC) $(FLAGS) -c $< -o $@

$(LIB): $(OBJECTS_LIB)
	mkdir -p $(LIBDIR)
	ar -rcs $(LIB) $(OBJECTS_LIB)


$(OBJECTS_LIB): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) $(FLAGS) -c $< -o $@

docs :
	$(DOCGEN)

clean :
	$(RM) -r doc/ $(OBJDIR) $(BINDIR) $(LIBDIR) $(TARNAME)
dist :
	tar -jcvf $(TARNAME) src include README.md Makefile Doxyfile
run: 
	./bin/JeuDeVie ./grilles/grille4.txt