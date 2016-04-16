/*
** msdl_screen.h for minisdl_cpp in /home/le-mai_s/librairie/minisdl_cpp/include
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Mon Nov  9 21:47:53 2015 sebastien le-maire
// Last update Sat Apr 16 13:25:53 2016 Sébastien Le Maire
*/

#ifndef MSDL_SCREEN_HPP_
# define MSDL_SCREEN_HPP_

# include <string>
# include <cstdlib>
# include <SDL/SDL.h>
# include "msdl_macro.hpp"
# include "msdl_image.hpp"
# include "msdl_font.hpp"
# include "msdl_surface.hpp"

namespace	msdl
{
  class	Screen : public msdl::Surface
  {
  public:
    Screen();
    virtual ~Screen();

    bool	init(const unsigned char opt = ALL_OFF,
		     const Uint16 width = 720,
		     const Uint16 height = 480,
		     std::string title = "Minisdl Project !");

    void	set_icon(Image &icon);

    void	update(void) const;

    void	blit(Image const &image, const Uint16 x = 0,
		     const Uint16 y = 0, SDL_Rect const *rect_src = NULL);

    void	blit(Font const &font, const Uint16 x = 0,
		     const Uint16 y = 0, SDL_Rect const *rect_src = NULL);

    bool	switch_fullscreen(void);

    bool	switch_resize(void);

    static bool	init_system(const unsigned char opt);

    static void	quit_system(const unsigned char opt);

  private:
    bool	m_init_success;
  };
}

#endif /* !MSDL_SCREEN_HPP_ */
