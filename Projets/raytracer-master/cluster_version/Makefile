##
## Makefile for Makefile in /home/merran_g/work/c_igraph/raytracer/merge
## 
## Made by Geoffrey Merran
## Login   <merran_g@epitech.net>
## 
## Started on  Sat Jun  7 22:43:37 2014 Geoffrey Merran
## Last update Sun Jun  8 12:11:21 2014 Geoffrey Merran
##

D_SERV	= server/
D_CLT	= client/
D_EDIT	= editor/
D_LAUN	= launcher/

all:
	make -C $(D_SERV)
	make -C $(D_CLT)
	make -C $(D_EDIT)

clean:
	(cd $(D_SERV); make clean)
	(cd $(D_CLT); make clean)
	(cd $(D_EDIT); make clean)

fclean:
	(cd $(D_SERV); make fclean)
	(cd $(D_CLT); make fclean)
	(cd $(D_EDIT); make fclean)

re: fclean all

.PHONY: all clean fclean re
