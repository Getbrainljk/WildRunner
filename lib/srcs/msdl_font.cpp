//
// msdl_font2.cpp for msdl_font2 in /home/le-mai_s/librairie/minisdl_cpp/srcs
//
// Made by Sébastien Le Maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Mon Jan 25 20:37:54 2016 Sébastien Le Maire
// Last update Wed Jan 27 15:01:57 2016 Sébastien Le Maire
//

#include <limits.h>
#include "msdl_font.hpp"

namespace		msdl
{
  Font::Font()
  {
  }

  Font::~Font()
  {
    if (m_surface)
      SDL_FreeSurface(m_surface);
    if (m_font)
      TTF_CloseFont(m_font);
  }

  bool			Font::init_ttf(void)
  {
    if (TTF_Init() == -1)
      return (false);
    return (true);
  }

  void			Font::close_ttf(void)
  {
    TTF_Quit();
  }

  bool			Font::load(char const *font_name,
				   unsigned int const font_size,
				   Uint8 floatingPrecision)
  {
    this->m_floating = floatingPrecision;
    return ((!(m_font = TTF_OpenFont(font_name, font_size))) ? false : true);
  }

  void		Font::get_rgb_color(const Uint32 color, SDL_Color &rgb)
  {
    if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
      {
	rgb.r = color & 0xFF;
	rgb.g = (color >> 8) & 0xFF;
        rgb.b = (color >> 16) & 0xFF;
      }
    else
      {
        rgb.r = (color >> 16) & 0xFF;
        rgb.g = (color >> 8) & 0xFF;
        rgb.b = color & 0xFF;
      }
  }
}
