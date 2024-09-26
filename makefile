
DEBUG ?= y

#set the compiler variable (by default gcc)
CC= gcc

#compilation flags variable
ifeq ($(DEBUG),y)
	CFLAG= -g -Wall 
else
	CFLAG= -O2
endif

BUILD_DIR=./build

# different name for the programme
EXEC= main

OBJECT = $(BUILD_DIR)/main.o $(BUILD_DIR)/core.o $(BUILD_DIR)/terminal.o $(BUILD_DIR)/dico_io.o $(BUILD_DIR)/string.o

all: $(EXEC)

$(EXEC): $(OBJECT)
	$(CC) $(CFLAG) -o $(EXEC) $(OBJECT)
	
$(BUILD_DIR)/%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@

# lazy dev => auto clean :D
# remove all generated files
clean:
	-@rm ./$(BUILD_DIR)/* $(EXEC)
	@echo "all compiled code removed"
