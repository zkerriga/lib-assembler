# ******************************************************************************* #
#                                                                             	  #
#     Makefile                                                   ♥           	  #
#                                                                 ¨/\_/\ ♥    	  #
#     By: zkerriga                                                 >^,^<     	  #
#                                                                   / \     	  #
#     Created: 2020-08-03 07:48:25 by zkerriga                     (___)__  	  #
#     Updated: 2020-08-05 20:51:03 by zkerriga                              	  #
#                                                                             	  #
# ******************************************************************************* #

NAME = libasm.a
HEAD = libasm.h
PROGRAM = libasm_test

OBJ_DIR = bin
SRC_DIR = src
BONUS_DIR = src_bonus

ACC = nasm
AFLAGS = -f macho64

CC = gcc
FLAGS = -Wall -Wextra -I. -I./$(TEST_DIR)

FILES = $(wildcard $(SRC_DIR)/*.s) $(wildcard $(BONUS_DIR)/*.s)
FILES_O = $(addprefix $(OBJ_DIR)/, $(FILES:.s=.o))

.PHONY: all
all: $(OBJ_DIR) $(NAME)
	@echo "\n\033[32m[+] The $(NAME) assembled!\033[0m\n"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/$(SRC_DIR) $(OBJ_DIR)/$(BONUS_DIR)
	mkdir $(OBJ_DIR)/$(TEST_DIR)

$(NAME): $(FILES_O)
	ar rcs $(NAME) $?

$(FILES_O): $(OBJ_DIR)/%.o: %.s $(HEAD)
	$(ACC) $(AFLAGS) $< -o $@

.PHONY: clean
clean:
	$(RM) -r $(OBJ_DIR)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

#######
# BEGIN
# Test
#

TEST_HEAD = tests.h
TEST_DIR = tests
TEST_FILES = $(wildcard $(TEST_DIR)/*.c) main.c
TEST_FILES_O = $(addprefix $(OBJ_DIR)/, $(TEST_FILES:.c=.o))

.PHONY: test
test: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): $(TEST_FILES_O) $(NAME)
	$(CC) $(FLAGS) $(TEST_FILES_O) $(NAME) -o $(PROGRAM)

$(TEST_FILES_O): $(OBJ_DIR)/%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

.PHONY: fcleantest
fcleantest:
	$(RM) $(PROGRAM) $(OBJ_DIR)/main.o

.PHONY: retest
retest: fcleantest test

#
# Test
# END
#######

#######
# BEGIN
# Bonus
#

.PHONY: bonus
bonus: all
	@echo "\n\033[32m[+] The super-$(NAME) assembled!\033[0m"

#
# Bonus
# END
#######
