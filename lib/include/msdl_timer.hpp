/*
** msdl_timer.h for minisdl_cpp in /home/le-mai_s/librairie/minisdl_cpp/include/
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Wed Nov 11 19:10:21 2015 sebastien le-maire
** Last update Wed Jan 27 15:17:02 2016 Sébastien Le Maire
*/

#ifndef MSDL_TIMER_HPP_
# define MSDL_TIMER_HPP_

# include <SDL/SDL.h>
# include "msdl_screen.hpp"

namespace	msdl
{
  class	Timer
  {
  public:
    Timer();
    ~Timer();

    bool	        init(msdl::Screen *screen, const Uint32 interval,
			     SDL_NewTimerCallback callback, void *param);

    msdl::Screen	*get_screen(void) const;

    void		*get_param(void) const;

  private:
    SDL_TimerID	m_timer;
    msdl::Screen	*m_screen;
    void		*m_param;
  };
}

#endif /* !MSDL_TIMER_HPP_ */
