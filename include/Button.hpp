//
// Button.hpp for Button in /home/le-mai_s/projet/ludum_dare_35/game/seb
//
// Made by Sébastien Le Maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Sun Apr 17 10:21:50 2016 Sébastien Le Maire
// Last update Mon Apr 18 19:42:19 2016 Sébastien Le Maire
//

#ifndef BUTTON_HPP_
# define BUTTON_HPP_

# include "minisdl.hpp"

namespace			Menu
{
  class				Button
  {
  public: /* ctor & dtor */
    Button(std::string const &name, msdl::Font &font,
	   Uint16 x, Uint16 y, Uint16 width, Uint16 height,
	   Uint32 colorFont, Uint32 colorBgOff, Uint32 colorBgOn);
    ~Button();

  public: /* Methods */
    void			checkOnOff(Uint32 mouseX, Uint32 mouseY);
    void			putOnSurface(msdl::Surface &surface);
    bool	       		push(Uint32 mouseX, Uint32 mouseY);

  private: /* attribute */
    std::string const		m_name;
    msdl::Font			&m_font;
    Uint16			m_x;
    Uint16			m_y;
    Uint16			m_width;
    Uint16			m_height;
    Uint32			m_colorFont;
    Uint32			m_colorBgOn;
    Uint32			m_colorBgOff;
    Uint32			m_selectColor;
  };
}

#endif /* !BUTTON_HPP_ */
