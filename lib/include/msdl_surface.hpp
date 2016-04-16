/*
** msdl_surface.h for minisdl.h in /home/le-mai_s/librairie/minisdl_cpp
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Sun Nov 22 04:02:35 2015 sebastien le-maire
// Last update Sat Apr 16 13:25:10 2016 Sébastien Le Maire
*/

#ifndef MSDL_SURFACE_HPP_
# define MSDL_SURFACE_HPP_

namespace	msdl
{
  class		Surface
  {
  public:
    Surface();
    virtual ~Surface();

  public:
    void		put_pixel(const Uint16 x, const Uint16 y,
				  const Uint32 color = 0xFFFFFFFF);
    Uint32		get_pixel(const Uint16 x, const Uint16 y) const;
    bool	        clear(Uint32 color = 0);
    Uint32		width(void) const;
    Uint32		height(void) const;
    SDL_Surface		*get_surface(void) const;
    void		blit(SDL_Surface *surface, const Uint16 x = 0,
			     const Uint16 y = 0, SDL_Rect const *rect_src = NULL);

  protected:
    SDL_Surface		*m_surface;

  };
}

#endif /* !MSDL_SURFACE_HPP_ */
