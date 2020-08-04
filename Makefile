# ******************************************************************************* #
#                                                                             	  #
#     Makefile                                                   ♥           	  #
#                                                                 ¨/\_/\ ♥    	  #
#     By: zkerriga                                                 >^,^<     	  #
#                                                                   / \     	  #
#     Created: 2020-08-03 07:48:25 by zkerriga                     (___)__  	  #
#     Updated: 2020-08-04 15:59:51 by zkerriga                              	  #
#                                                                             	  #
# ******************************************************************************* #

NAME = libasm.a
HEAD = libasm.h
PROGRAM = libasm_test

OBJ_DIR = bin
SRC_DIR = src
BONUS_DIR = src_bonus

ACC = nasm
AFLAGS = -f elf64

CC = tcc
FLAGS = -Wall -Wextra -Werror -I.

FILES = $(wildcard $(SRC_DIR)/*.s) $(wildcard $(BONUS_DIR)/*.s)
FILES_O = $(addprefix $(OBJ_DIR)/, $(FILES:.s=.o))

.PHONY: all
all: $(OBJ_DIR) $(NAME)
	@echo -e "\n\e[32m[+] The $(NAME) assembled!\e[0m"

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/$(SRC_DIR) $(OBJ_DIR)/$(BONUS_DIR)

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

.PHONY: test
test: $(PROGRAM)
	./$(PROGRAM)

$(PROGRAM): $(NAME) main.o
	$(CC) $(FLAGS) $(OBJ_DIR)/main.o $(NAME) -o $(PROGRAM) 

main.o: $(FILES_O) $(HEAD)
	$(CC) $(FLAGS) -c main.c -o $(OBJ_DIR)/main.o

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
	@echo -e "\n\e[32m[+] The super-$(NAME) assembled!\e[0m"

#
# Bonus
# END
#######
