//
// msdl_font2.hpp for minisdl in /home/le-mai_s/librairie/minisdl_cpp/srcs
//
// Made by Sébastien Le Maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Mon Jan 25 20:39:10 2016 Sébastien Le Maire
// Last update Wed Jan 27 15:21:05 2016 Sébastien Le Maire
//

#ifndef MSDL_FONT_HPP_
# define MSDL_FONT_HPP_

# include <SDL/SDL.h>
# include <SDL/SDL_ttf.h>
# include <sstream>
# include <iomanip>
# include "msdl_surface.hpp"
# include "msdl_macro.hpp"

namespace		msdl
{
  class			Font : public msdl::Surface
  {
  public:
    typedef enum		e_type
      {
				UNDEFINED = -1,
				SHADED,
				SOLID,
				BLENDED
      }				t_type;

  public: /* ctor && dtor */
    Font();
    ~Font();

  public: /* Methods */
    bool		load(char const *font_name, unsigned int const font_size = 50,
			     Uint8 floatingPrecision = 2);

  public: /* Template */
    template<typename T>
    bool			write(T const &text,
				      SDL_Surface *surface,
				      msdl::Font::t_type type,
				      Uint16 const x,
				      Uint16 const y,
				      Uint32 const color_txt = 0xFFFFFF,
				      Uint32 const color_bg = 0)
    {
      std::ostringstream	oss;
      SDL_Color			ctext;
      SDL_Color			cbg;
      SDL_Rect			pos;

      oss << std::fixed << std::setprecision(this->m_floating) << text;
      if (this->m_surface)
	{
	  SDL_FreeSurface(this->m_surface);
	  this->m_surface = NULL;
	}
      msdl::Font::get_rgb_color(color_txt, ctext);
      msdl::Font::get_rgb_color(color_bg, cbg);
      if (type == SHADED)
	this->m_surface = TTF_RenderText_Shaded(this->m_font, oss.str().c_str(),
						ctext, cbg);
      else if (type == SOLID)
	this->m_surface = TTF_RenderText_Solid(m_font, oss.str().c_str(), ctext);
      else if (type == BLENDED)
	this->m_surface = TTF_RenderText_Blended(m_font, oss.str().c_str(), ctext);
      if (!this->m_surface)
	return (false);
      if (surface)
	{
	  pos.x = x;
	  pos.y = y;
	  pos.w = this->m_surface->w;
	  pos.h = this->m_surface->h;
	  SDL_BlitSurface(m_surface, NULL, surface, &pos);
	}
      return (true);
    }

  private: /* Attributes */
    TTF_Font		*m_font;
    Uint8		m_floating;


  public: /* Static public methods */
    static bool		init_ttf(void);
    static void	        close_ttf(void);

  private: /* Static private methods */
    static void		get_rgb_color(Uint32 const color, SDL_Color &rgb);
  };
}

#endif /* !MSDL_FONT_HPP_ */
