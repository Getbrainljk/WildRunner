//
// msdl_image.cpp for minisdl_cpp in /home/le-mai_s/librairie/minisdl_cpp/srcs
//
// Made by sebastien le-maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Mon Nov  9 22:27:35 2015 sebastien le-maire
// Last update Wed Jan 27 15:13:14 2016 Sébastien Le Maire
//

#include "msdl_image.hpp"

namespace	msdl
{
  Image::Image()
  {
    m_surface = NULL;
  }

  Image::~Image()
  {
    if (m_surface)
      SDL_FreeSurface(m_surface);
  }

  bool	        Image::init(const Uint16 width, const Uint16 height,
			    const Uint32 color)
  {
    Uint8	rgb[3];
    Uint8	index;
    char       	endian[2];

    if (!(m_surface = SDL_CreateRGBSurface(SDL_HWSURFACE, width, height,
					 32, 0, 0, 0, 0)))
      return (false);
    index = 0;
    endian[0] = (SDL_BYTEORDER == SDL_BIG_ENDIAN) ? -8 : 8;
    endian[1] = (endian[0] < 0) ? 16 : 0;
    while (index < 3)
      {
	rgb[index] = (color >> (endian[1] + (endian[0] * index))) & 0xFF;
	++index;
      }
    SDL_FillRect(m_surface, NULL,
		 SDL_MapRGB(m_surface->format, rgb[2], rgb[1], rgb[0]));
    return (true);
  }

  bool		Image::init(const char *image_name)
  {
    if (!(m_surface = IMG_Load(image_name)))
      return (false);
    return (true);
  }

  bool		Image::transparency_color(Uint32 color)
  {
    Uint8	index;
    char       	endian[2];
    Uint8	rgb[3];

    index = 0;
    endian[0] = (SDL_BYTEORDER == SDL_BIG_ENDIAN) ? -8 : 8;
    endian[1] = (endian[0] < 0) ? 16 : 0;
    while (index < 3)
      {
	rgb[index] = (color >> (endian[1] + (endian[0] * index))) & 0xFF;
	++index;
      }
    if (SDL_SetColorKey(m_surface, SDL_SRCCOLORKEY,
			SDL_MapRGB(m_surface->format, rgb[2], rgb[1], rgb[0])))
      return (false);
    return (true);
  }

  bool		Image::transparency_alpha(Uint8 alpha)
  {
    if (SDL_SetAlpha(m_surface, SDL_SRCALPHA, alpha))
      return (false);
    return (true);
  }
}
