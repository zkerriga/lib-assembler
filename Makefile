# ******************************************************************************* #
#                                                                             	  #
#     Makefile                                                   ♥           	  #
#                                                                 ¨/\_/\ ♥    	  #
#     By: zkerriga                                                 >^,^<     	  #
#                                                                   / \     	  #
#     Created: 2020-08-03 07:48:25 by zkerriga                     (___)__  	  #
#     Updated: 2020-08-03 07:55:05 by zkerriga                              	  #
#                                                                             	  #
# ******************************************************************************* #

NAME = libasm.a

CC = nasm

.PHONY: all
all:
	echo $

.PHONY: clean
clean:
	echo $

.PHONY: fclean
fclean:
	echo $

.PHONY: re
re: fclean all
	echo $
