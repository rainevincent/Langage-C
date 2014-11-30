##
## Makefile for Makefile in /home/merran_g/work/c_elem/corewar
## 
## Made by Geoffrey Merran
## Login   <merran_g@epitech.net>
## 
## Started on  Wed Apr  2 13:52:55 2014 Geoffrey Merran
## Last update Sat Apr 12 20:37:19 2014 Geoffrey Merran
##

VM_FOLDER	= corewar/
ASM_FOLDER	= asm/

all:
	make -C $(VM_FOLDER)
	make -C $(ASM_FOLDER)

clean:
	(cd $(VM_FOLDER); make clean)
	(cd $(ASM_FOLDER); make clean)

fclean:
	(cd $(VM_FOLDER); make fclean)
	(cd $(ASM_FOLDER); make fclean)

re:	fclean all

.PHONY:	all clean fclean re
