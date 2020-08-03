# ******************************************************************************* #
#                                                                             	  #
#     Makefile                                                   ♥           	  #
#                                                                 ¨/\_/\ ♥    	  #
#     By: zkerriga                                                 >^,^<     	  #
#                                                                   / \     	  #
#     Created: 2020-08-03 07:48:25 by zkerriga                     (___)__  	  #
#     Updated: 2020-08-03 12:38:50 by zkerriga                              	  #
#                                                                             	  #
# ******************************************************************************* #

NAME = libasm.a

CC = nasm

.PHONY: all
all:
	nasm -f elf64 ft_strlen.s -o ft_strlen.o
	@echo $
	gcc -I. main.c ft_strlen.o -o test
	@echo $
	./test

.PHONY: clean
clean:
	$(RM) *.o

.PHONY: fclean
fclean:
	echo $

.PHONY: re
re: fclean all
	echo $
