//
// Button.cpp for Button in /home/le-mai_s/projet/ludum_dare_35/game/seb
//
// Made by Sébastien Le Maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Sun Apr 17 10:21:53 2016 Sébastien Le Maire
// Last update Tue Apr 19 02:43:43 2016 Sébastien Le Maire
//

#include "Button.hpp"

namespace			Menu
{
  Button::Button(std::string const &name, msdl::Font &font,
		 Uint16 x, Uint16 y, Uint16 width, Uint16 height,
		 Uint32 colorFont, Uint32 colorBgOff, Uint32 colorBgOn) :
    m_name(name), m_font(font), m_x(x), m_y(y), m_width(width), m_height(height),
    m_colorFont(colorFont), m_colorBgOn(colorBgOn), m_colorBgOff(colorBgOff)
  {
  }

  Button::~Button(void)
  {
  }

  /*
  ** Methods
  */

  void				Button::checkOnOff(Uint32 mouseX, Uint32 mouseY)
  {
    this->m_selectColor = this->m_colorBgOff;
    if ((mouseY >= this->m_y) && (mouseY <= (this->m_y + this->m_height)))
      if ((mouseX >= this->m_x) && (mouseX <= (this->m_x + this->m_width)))
	this->m_selectColor = this->m_colorBgOn;
  }

  void			        Button::putOnSurface(msdl::Surface &surface)
  {
    msdl::Image			img;

    img.init(this->m_width, this->m_height, this->m_selectColor);
    this->m_font.write<std::string>(this->m_name, img.get_surface(),
				    msdl::Font::SOLID,
				    (this->m_width / 2) - ((this->m_name.size() / 2) * 30),
				    (this->m_height / 2) - 25, this->m_colorFont);
    surface.blit(img.get_surface(), this->m_x, this->m_y);
  }

  bool				Button::push(Uint32 mouseX, Uint32 mouseY)
  {
    if ((mouseY >= this->m_y) && (mouseY <= (this->m_y + this->m_height)))
      if ((mouseX >= this->m_x) && (mouseX <= (this->m_x + this->m_width)))
	return (true);
    return (false);
  }
}
