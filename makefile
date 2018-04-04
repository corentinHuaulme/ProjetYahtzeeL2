# A remplacer par votre path vers la SDL2
INCLUDE_DIR=/home/corentin/Documents/Cours/ProjetYahtzeeL2/SDL2-2.0.8/bin/include
LIB_DIR=/home/corentin/Documents/Cours/ProjetYahtzeeL2/SDL2-2.0.8/bin/lib

OPTS=-L${LIB_DIR} -lSDL2 -lSDL2_ttf -lSDL2_image -I${INCLUDE_DIR}
# project name (generate executable with this name)
TARGET   = yahtzee

CC       = gcc
# compiling flags here
CFLAGS   = -std=c99 -Wall -I.

LINKER   = gcc
# linking flags here
LFLAGS   = -Wall -I. -lm

# change these to proper directories where each file should be
SRCDIR   = src
OBJDIR   = obj
BINDIR   = build

DIRS	 = $(OBJDIR) $(BINDIR) 

.PHONY: DIRS
all: $(DIRS) $(BINDIR)/$(TARGET)

$(OBJDIR):
	mkdir -p $(OBJDIR)
$(BINDIR):
	mkdir -p $(BINDIR)

SOURCES  := $(wildcard $(SRCDIR)/*.c)
INCLUDES := $(wildcard $(SRCDIR)/*.h)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
rm       = rm -f


$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $(OBJECTS) $(LFLAGS) -o $@  ${OPTS}
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@  ${OPTS}
	@echo "Compiled "$<" successfully!"

.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONY: remove
remove: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"



