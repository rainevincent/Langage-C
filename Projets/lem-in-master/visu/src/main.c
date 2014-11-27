/*
** main.c for Visu in /home/jobertomeu/Work/lemin/visu
** 
** Made by Joris Bertomeu
** Login   <jobertomeu@epitech.net>
** 
** Started on  Wed Apr 30 15:33:38 2014 Joris Bertomeu
** Last update Sun May  4 20:01:08 2014 Joris Bertomeu
*/

#include "visu.h"

void		init_start(int ac, char **argv, t_system *sys)
{
  sys->func = 0;
  sys->screen = SDL_SetVideoMode(WIDTH, HEIGHT,
				 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  sys->map = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, 32, 0, 0, 0, 0);
  sys->tour = 0;
  if (ac >= 2)
    sys->speed = 1000000 / atoi(argv[1]);
  else
    sys->speed = 1000000;
  TTF_Init();
  if ((sys->font = TTF_OpenFont("font/font.ttf", 15)) == NULL)
    printe(TTF_GetError());
}

void	check_nbr_ants(char *str, t_system *sys)
{
  if (atoi(str) >= 1023)
    {
      printf("Error : Maximum number of ants is 1024 for Visu .. Sorry\n");
      exit (0);
    }
  else
    sys->nbr_ants = atoi(str);
}

void	printe(char *str)
{
  printf("%s", str);
  exit (-1);
}

int		main(int argc, char *argv[])
{
  SDL_Event	event;
  int		continuef;
  t_system	*sys;

  sys = xmalloc(sizeof(*sys));
  memset(sys, 0, sizeof(*sys));
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    printe("Error : SDL Init\n");
  atexit(SDL_Quit);
  continuef = 1;
  SDL_WM_SetCaption("Lem-In - Visu", NULL);
  init_start(argc, argv, sys);
  SDL_EnableKeyRepeat(10, 10);
  parse(sys);
  update_screen(sys);
  while (continuef)
    {
      SDL_WaitEvent(&event);
      if (event.type == SDL_QUIT)
	continuef = 0;
    }
  SDL_Quit();
  return 0;
}
