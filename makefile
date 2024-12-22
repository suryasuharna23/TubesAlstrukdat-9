# Compiler
CC = gcc

# Compiler flags
CFLAGS = -I. \
         -IADT/User \
         -IADT/Barang \
         -IADT/Mesin \
         -IADT/Map \
         -IADT/Stack \
         -IADT/Queue \
         -IADT/LinkedList \
         -Icommand/Score \
         -Icommand/Tebak_Angka \
         -Icommand/Load \
         -Icommand/Save \
         -Icommand/Register \
         -Icommand/Help \
         -Icommand/Login \
         -Icommand/Work \
         -Icommand/WORDL3 \
         -Icommand/Store \
         -Icommand/Profile \
         -Icommand/Cart \
         -Icommand/History \
         -Icommand/Wishlist \
         -IASCII \
         -ILoading \
         -Icommand/Random_Number \
         -Icommand/Graph \
         -Icommand/Clear \
         -IBoolean \
         -Iconfig

# Source directories
SRC_DIR = .\src
ADT_DIR = $(SRC_DIR)\ADT
COMMAND_DIR = $(SRC_DIR)\command
ASCII_DIR = $(SRC_DIR)\ASCII
LOADING_DIR = $(SRC_DIR)\Loading
BOOLEAN_DIR = $(SRC_DIR)\Boolean
CONFIG_DIR = $(SRC_DIR)\config

# Source files
SRC_FILES = $(SRC_DIR)\console_main.c \
            $(ADT_DIR)\User\user.c \
            $(ADT_DIR)\Barang\barang.c \
            $(ADT_DIR)\Mesin\mesinkata.c \
            $(ADT_DIR)\Mesin\mesinkarakter.c \
            $(ADT_DIR)\Map\map.c \
            $(ADT_DIR)\Stack\stack.c \
            $(ADT_DIR)\Queue\queue.c \
            $(ADT_DIR)\LinkedList\listlinier.c \
            $(COMMAND_DIR)\Score\score.c \
            $(COMMAND_DIR)\Tebak_Angka\tebak_angka.c \
            $(COMMAND_DIR)\Load\load.c \
            $(COMMAND_DIR)\Save\save.c \
            $(COMMAND_DIR)\Register\register.c \
            $(COMMAND_DIR)\Help\help.c \
            $(COMMAND_DIR)\Login\login.c \
            $(COMMAND_DIR)\Work\work.c \
            $(COMMAND_DIR)\WORDL3\wordl3.c \
            $(COMMAND_DIR)\Store\store.c \
            $(COMMAND_DIR)\Profile\profile.c \
            $(COMMAND_DIR)\Cart\cart.c \
            $(COMMAND_DIR)\History\history.c \
            $(COMMAND_DIR)\Wishlist\wishlist.c \
            $(ASCII_DIR)\ascii.c \
            $(LOADING_DIR)\Loadingscreen.c \
            $(COMMAND_DIR)\Random_Number\random_number.c \
            $(COMMAND_DIR)\Graph\graph.c \
            $(COMMAND_DIR)\Clear\clear.c

# Object files
OBJ_FILES = $(SRC_FILES:.c=.o)

# Data files to include
DATA_FILES = $(CONFIG_DIR)\default.txt $(CONFIG_DIR)\floppydiskdrive.txt

# Output executable
OUTPUT = runPURRMART

# Default target
all: $(OUTPUT) copy-data

# Rule to build the executable
$(OUTPUT): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(OUTPUT) $(CFLAGS)

# Rule to copy data files
copy-data:
	@echo "Copying data files..."
	copy $(CONFIG_DIR)\default.txt .
	copy $(CONFIG_DIR)\floppydiskdrive.txt .

# Rule to build object files
$(SRC_DIR)\%.o: $(SRC_DIR)\%.c
	$(CC) -c $< -o $@ $(CFLAGS)

# Clean target
clean:
	del /Q $(OUTPUT)
	del /Q $(OBJ_FILES)
	del /Q default.txt
	del /Q floppydiskdrive.txt

# Phony targets
.PHONY: all clean copy-data
