
#set the compiler variable (by default gcc)
CC= gcc

#compilation flags variable
DEBUG_CFLAG= -g -Wall
OPTIMIZE_CFLAG= -O2
CFLAG=

# .SILENT => doesn't print command at execution
#.SILENT: 
# .PHONY => allow to use multiple time this (doens't check target)
.PHONY: clean

# different name for the programme
EXEC_DEBUG= main_d
EXEC_RELEASE= main

all: debug release

# set CFLAG with the correct flag
debug: CFLAG = $(DEBUG_CFLAG)
debug: $(EXEC_DEBUG)

release: CFLAG = $(OPTIMIZE_CFLAG)
release: $(EXEC_RELEASE)

# compile
$(EXEC_DEBUG): main.o core.o terminal.o dico_io.o string.o
	$(CC) $(CFLAG) -o $@ $^
	echo "debug compiled"


$(EXEC_RELEASE): main.o core.o terminal.o dico_io.o string.o
	$(CC) $(CFLAG) -o $@ $^
	echo "release compiled"

# lazy dev => auto clean :D
# remove all generated files
clean:
	rm ./*.o $(EXEC_DEBUG) $(EXEC_RELEASE)
	echo "all compiled code removed"
