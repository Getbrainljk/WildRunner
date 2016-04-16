//
// Sprite.cpp for minisdl in /home/le-mai_s/projet/ludum_dare_35/game/seb
//
// Made by Sébastien Le Maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Sat Apr 16 12:36:38 2016 Sébastien Le Maire
// Last update Sat Apr 16 20:42:01 2016 Sébastien Le Maire
//

#include "Sprite.hpp"

namespace			msdl
{
  Sprite::Sprite(msdl::Image &image, unsigned int nbImg,
		 int width, int height, Uint32 speed)
    : m_img(image), m_nbImg(nbImg), m_index(0), m_time(0), m_speed(speed)
  {
    this->m_rect.x = 0;
    this->m_rect.y = 0;
    this->m_rect.w = width;
    this->m_rect.h = height;
    this->m_elemMaxPerLine = image.width() / width;
  }

  Sprite::~Sprite(void)
  {
  }

  /*
  ** Methods
  */

  void				Sprite::nextSprite(void)
  {
    Uint32			currentTime = SDL_GetTicks();
    Uint32     			dec_time = currentTime - this->m_time;

    if (dec_time > this->m_speed)
      {
	this->m_index = (this->m_index + 1) % this->m_nbImg;
	this->m_time = currentTime;
      }
  }

  /*
  ** Accessor
  */

  SDL_Rect const		*Sprite::getRectSprite(void)
  {
    this->m_rect.x = (this->m_rect.w * this->m_index) % this->m_img.width();
    this->m_rect.y = ((this->m_rect.h * (this->m_index / this->m_elemMaxPerLine))
		      % this->m_img.height());
    return (&this->m_rect);
  }

  msdl::Image const		&Sprite::getImage(void)
  {
    return (this->m_img);
  }

  void				Sprite::resetIndex(void)
  {
    this->m_index = 0;
  }
}
