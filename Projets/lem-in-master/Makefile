##
## Makefile for Makefile in /home/merran_g/work/c_elem/lem-in
## 
## Made by Geoffrey Merran
## Login   <merran_g@epitech.net>
## 
## Started on  Sun Apr 27 16:26:35 2014 Geoffrey Merran
## Last update Sun Apr 27 16:28:51 2014 Geoffrey Merran
##

LEM_FOLDER	= lem_in/
VIS_FOLDER	= visu/

all:
	make -C $(LEM_FOLDER)
	make -C $(VIS_FOLDER)

clean:
	(cd $(LEM_FOLDER); make clean)
	(cd $(VIS_FOLDER); make clean)

fclean:
	(cd $(LEM_FOLDER); make fclean)
	(cd $(VIS_FOLDER); make fclean)

re:	fclean all

.PHONY:	all clean fclean re
