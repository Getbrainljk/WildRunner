//
// main.cpp for  in /home/eizenb_m/rendu/game/max
// 
// Made by max eizenberg
// Login   <eizenb_m@epitech.net>
// 
// Started on  Sat Apr 16 16:15:35 2016 max eizenberg
// Last update Sat Apr 16 17:11:25 2016 max eizenberg
//

#include "../lib/include/minisdl.hpp"

int	main()
{
  msdl::Screen	screen;
  msdl::Image	image;
  msdl::Event	event;

  screen.init();
  image.init("/home/eizenb_m/Downloads/lol.png");
  screen.blit(image);
  screen.update();
  event.loop(screen);
}
