/*
** msdl_image.h for minisdl_cpp in /home/le-mai_s/librairie/minisdl_cpp/include
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Mon Nov  9 22:18:34 2015 sebastien le-maire
** Last update Wed Jan 27 15:13:05 2016 Sébastien Le Maire
*/

#ifndef MSDL_IMAGE_HPP_
# define MSDL_IMAGE_HPP_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "msdl_surface.hpp"

namespace	msdl
{
  class Image : public msdl::Surface
  {
  public:
    Image();
    virtual ~Image();

    bool	init(const Uint16 width, const Uint16 height,
		     const Uint32 color = 0);
    bool	init(const char *image_name);
    bool	transparency_color(Uint32 color);
    bool	transparency_alpha(Uint8 alpha);

  private:
  };
}

#endif /* !MSDL_IMAGE_HPP_ */
