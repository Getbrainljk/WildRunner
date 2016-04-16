//
// msdl_timer.cpp for minisdl_cpp in /home/le-mai_s/librairie/minisdl_cpp/srcs/
//
// Made by sebastien le-maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Wed Nov 11 19:13:00 2015 sebastien le-maire
// Last update Wed Jan 27 15:16:45 2016 Sébastien Le Maire
//

#include <cstdlib>
#include "msdl_timer.hpp"

namespace	msdl
{

  Timer::Timer()
  {
    m_timer = NULL;
  }

  Timer::~Timer()
  {
    if (m_timer)
      SDL_RemoveTimer(m_timer);
  }

  bool		Timer::init(msdl::Screen *screen, const Uint32 interval,
			    SDL_NewTimerCallback callback, void *param)
  {
    m_screen = screen;
    m_param = param;
    if (!(m_timer = SDL_AddTimer(interval, callback, this)))
      return (false);
    return (true);
  }

  msdl::Screen	*Timer::get_screen(void) const
  {
    return (m_screen);
  }

  void		*Timer::get_param(void) const
  {
    return (m_param);
  }
}
