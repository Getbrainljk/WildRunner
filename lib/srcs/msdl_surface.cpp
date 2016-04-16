//
// msdl_surface.cpp for minisdl_cpp in /home/le-mai_s/librairie/minisdl_cpp
//
// Made by sebastien le-maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Sun Nov 22 03:58:45 2015 sebastien le-maire
// Last update Sat Apr 16 13:32:04 2016 Sébastien Le Maire
//

#include <stdlib.h>
#include <SDL/SDL.h>
#include "msdl_surface.hpp"

namespace	msdl
{
  Surface::Surface()
  {
    m_surface = NULL;
  }

  Surface::~Surface()
  {
  }

  void		Surface::put_pixel(const Uint16 x, const Uint16 y,
				   const Uint32 color)
  {
    Uint8	bpp;
    Uint8	*pix;
    Uint8	index;
    char       	endian[2];

    bpp = m_surface->format->BytesPerPixel;
    pix = (Uint8 *)m_surface->pixels + y * m_surface->pitch + x * bpp;
    if (bpp == 1)
      *pix = color;
    else if (bpp == 2)
      *(Uint16 *)pix = color;
    else if (bpp == 3)
      {
	index = 0;
	endian[0] = (SDL_BYTEORDER == SDL_BIG_ENDIAN) ? -8 : 8;
	endian[1] = (endian[0] < 0) ? 16 : 0;
	while (index < 3)
	  {
	    pix[index] = (color >> (endian[1] + (endian[0] * index))) & 0xFF;
	    ++index;
	  }
      }
    else
      *(Uint32 *)pix = color;
  }

  Uint32	Surface::get_pixel(const Uint16 x, const Uint16 y) const
  {
    Uint8	bpp;
    Uint8	*pix;
    char	ed[2];

    bpp = m_surface->format->BytesPerPixel;
    pix = (Uint8 *)m_surface->pixels + y * m_surface->pitch + x * bpp;
    if (bpp == 1)
      return (*pix);
    else if (bpp == 2)
      return (*(Uint16 *)pix);
    else if (bpp == 3)
      {
	ed[0] = (SDL_BYTEORDER == SDL_BIG_ENDIAN) ? 16 : 0;
	ed[1] = (ed[0]) ? 0 : 16;
	return (pix[0] << (16 * ed[0]) | pix[1] << 8 | pix[2] << (16 * ed[1]));
      }
    else
      return (*(Uint32 *)pix);
    return (0);
  }

  bool		Surface::clear(Uint32 color)
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
    if (SDL_FillRect(m_surface, NULL,
		     SDL_MapRGB(m_surface->format, rgb[2], rgb[1], rgb[0])))
      return (false);
    return (true);
  }

  Uint32	Surface::width(void) const
  {
    return (m_surface->w);
  }

  Uint32	Surface::height(void) const
  {
    return (m_surface->h);
  }

  SDL_Surface	*Surface::get_surface(void) const
  {
    return (m_surface);
  }

  void		Surface::blit(SDL_Surface *surface, const Uint16 x,
			      const Uint16 y, SDL_Rect const *rect_src)
  {
    SDL_Rect	pos;

    pos.x = x;
    pos.y = y;
    pos.w = m_surface->w;
    pos.h = m_surface->h;
    SDL_BlitSurface(surface, const_cast<SDL_Rect *>(rect_src),
		    m_surface, &pos);
  }
}
