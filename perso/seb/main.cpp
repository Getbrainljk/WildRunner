//
// main.cpp for undefined in /home/le-mai_s/projet/ludum_dare_35/game/seb
//
// Made by Sébastien Le Maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Sat Apr 16 12:28:07 2016 Sébastien Le Maire
// Last update Sun Apr 17 14:07:44 2016 Sébastien Le Maire
//

#include "Button.hpp"
#include "minisdl.hpp"

bool			keyEvent(msdl::Screen &, SDLKey key,
				 SDLMod , void *)
{
  if (key == SDLK_ESCAPE)
    return (false);
  return (true);
}

bool			gameLoop(msdl::Screen &screen, void *param)
{
  Menu::Button		*button = static_cast<Menu::Button *>(param);

  screen.update();
  button->putOnSurface(screen);
  return (true);
}

bool			mouseEvent(msdl::Screen &, Uint8, Uint16 *mouse, void *param)
{
  Menu::Button		*button = static_cast<Menu::Button *>(param);

  if (button->push(mouse[0], mouse[1]))
    return (false);
  return (true);
}

bool			motionEvent(msdl::Screen &, Uint16 x, Uint16 y, void *param)
{
  Menu::Button		*button = static_cast<Menu::Button *>(param);

  button->checkOnOff(x, y);
  return (true);
}

int			main(void)
{
  msdl::Screen		screen;

  if (msdl::Font::init_ttf())
    {
      msdl::Event      	event;
      msdl::Font	font;
      Menu::Button     	button("Quit", font, 425, 350, 200, 100,
			       0xFFFFFF, 0xC7C7C7, 0xFF0000);

      if (!(font.load("CloisterBlack.ttf")))
	return (EXIT_FAILURE);
      if (screen.init(ALL_OFF, 1050, 900, "Wild Runner"))
	{
	  event.set_key(keyEvent);
	  event.set_mouse(mouseEvent, NULL, motionEvent);
	  event.set_fct_loop(gameLoop);
	  event.loop(screen, &button);
	}
    }
  return (EXIT_SUCCESS);
}
