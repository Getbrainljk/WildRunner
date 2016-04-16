#include <SDL/SDL.h>
#include "Character.hpp"

int main()
{
  Character c;
  SDL_Init(SDL_INIT_VIDEO);
  SDL_Surface *ecran = SDL_SetVideoMode(500, 500, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  SDL_Event event;

  SDL_WM_SetCaption("", NULL);
  while (true)
    {
      SDL_PollEvent(&event);
      if (event.key.keysym.sym == SDLK_ESCAPE)
	exit(0);

      SDL_Flip(ecran);
      SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 121, 248, 248));
    }
  
}
