//
// Sprite.hpp for minisdl in /home/le-mai_s/projet/ludum_dare_35/game/seb
//
// Made by Sébastien Le Maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Sat Apr 16 12:35:07 2016 Sébastien Le Maire
// Last update Sat Apr 16 20:42:54 2016 Sébastien Le Maire
//

#ifndef SPRITE_HPP_
# define SPRITE_HPP_

# include "msdl_image.hpp"

namespace			msdl
{
  class				Sprite
  {
  public: /* ctor & dtor */
    Sprite(msdl::Image &image, unsigned int nbImg,
	   int width, int height, Uint32 speed);
    ~Sprite(void);

  public: /* Methods */
    void			nextSprite(void);

  public: /* Accessor */
    SDL_Rect const		*getRectSprite(void);
    msdl::Image const		&getImage(void);
    void			resetIndex(void);

  private:
    msdl::Image			&m_img;
    unsigned int		m_nbImg;
    unsigned int		m_index;
    Uint32			m_time;
    Uint32			m_speed;
    Uint32			m_elemMaxPerLine;
    SDL_Rect			m_rect;
  };
}

#endif /* !SPRITE_HPP_ */
