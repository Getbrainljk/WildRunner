//
// msdl_event.cpp for minisdl in /home/le-mai_s/librairie/minisdl_cpp
//
// Made by sebastien le-maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Sat Jan  2 20:48:39 2016 sebastien le-maire
// Last update Sun Apr 17 13:59:42 2016 Sébastien Le Maire
//

#include <cstdlib>
#include "msdl_event.hpp"

namespace	msdl
{
  Event::Event()
  {
    unsigned int	i;

    m_continu = true;
    m_time[0] = 0;
    m_time[1] = 0;
    m_key[0] = NULL;
    m_key[1] = NULL;
    m_mouse[0] = NULL;
    m_mouse[1] = NULL;
    m_motion = NULL;
    m_fct_loop = NULL;
    m_fct_ogl = NULL;
    i = 0;
    while (i < (unsigned int)SDLK_LAST)
      {
	m_keyboard[i] = false;
	++i;
      }
  }

  Event::~Event()
  {
  }

  void	Event::set_key(bool (*keypress)(KEY_PARAM_EVENT),
		       bool (*keyrelease)(KEY_PARAM_EVENT))
  {
    m_key[0] = keypress;
    m_key[1] = keyrelease;
  }

  void	Event::set_mouse(bool (*mousepress)(MOUSE_PARAM_EVENT),
			 bool (*mouserelease)(MOUSE_PARAM_EVENT),
			 bool (*mousemotion)(MOTION_PARAM_EVENT))
  {
    m_mouse[0] = mousepress;
    m_mouse[1] = mouserelease;
    m_motion = mousemotion;
  }

  void	Event::set_fct_loop(bool (*fct_loop)(FCT_LOOP_PARAM_EVENT))
  {
    m_fct_loop = fct_loop;
  }

  void	Event::set_ogl(bool (*fct_ogl)(void *))
  {
    m_fct_ogl = fct_ogl;
  }

  bool	Event::motion(msdl::Screen &screen, void *param)
  {
    if (m_motion)
      return (m_motion(screen, m_event.button.x,
		       m_event.button.y, param));
    return (true);
  }

  bool	Event::mouse(msdl::Screen &screen, void *param,
		     const Uint8 index)
  {
    Uint16	mouse[2];

    if (m_mouse[index])
      {
	mouse[0] = m_event.button.x;
	mouse[1] = m_event.button.y;
	return (m_mouse[index](screen, m_event.button.button, mouse, param));
      }
    return (true);
  }

  bool		Event::key(msdl::Screen &screen, void *param,
			   const Uint8 index)
  {
    m_keyboard[m_event.key.keysym.sym] = (index) ? false : true;
    if (m_key[index])
      return (m_key[index](screen, m_event.key.keysym.sym,
			   m_event.key.keysym.mod, param));
    return (true);
  }

  void				Event::event(msdl::Screen &screen, void *param)
  {
    Uint8			index;
    static SDL_EventType	ev_type[5] =
      {
	SDL_KEYDOWN, SDL_KEYUP,
	SDL_MOUSEBUTTONDOWN, SDL_MOUSEBUTTONUP, SDL_MOUSEMOTION
      };

    index = 0;
    while ((index < 5) && (m_event.type != ev_type[index]))
      ++index;
    if (m_event.type == SDL_QUIT)
      m_continu = false;
    else if (index < 2)
      m_continu = this->key(screen, param, index);
    else if (index < 4)
      m_continu = this->mouse(screen, param, index - 2);
    else if (index == 4)
      m_continu = this->motion(screen, param);
  }

  void	Event::loop(msdl::Screen &screen, void *param, Uint32 frame)
  {
    frame = ((!frame) || (frame > 1000)) ? 33 : (1000 / frame);
    this->m_continu = true;
    while (m_continu)
      {
      	if ((m_fct_loop) || (m_fct_ogl))
	  while (SDL_PollEvent(&m_event))
	    this->event(screen, param);
	else
	  {
	    SDL_WaitEvent(&m_event);
	    this->event(screen, param);
	  }
	if ((m_fct_loop) && (m_continu))
	  {
	    m_time[0] = SDL_GetTicks();
	    if ((m_time[0] - m_time[1]) > frame)
	      {
		m_continu = m_fct_loop(screen, param);
		m_time[1] = m_time[0];
	      }
	    else
	      SDL_Delay(frame - (m_time[0] - m_time[1]));
	  }
	if ((m_fct_ogl) && (m_continu))
	  m_continu = m_fct_ogl(param);
      }
  }

  void		Event::state(const unsigned char opt, const bool state_enable)
  {
    int		flags_state;
    Uint32	type;

    flags_state = (state_enable) ? SDL_ENABLE : SDL_IGNORE;
    type = 0;
    if (opt & MSDL_KEYPRESS)
      type |= SDL_KEYDOWN;
    if (opt & MSDL_KEYRELEASE)
      type |= SDL_KEYUP;
    if (opt & MSDL_MOUSEPRESS)
      type |= SDL_MOUSEBUTTONDOWN;
    if (opt & MSDL_MOUSERELEASE)
      type |= SDL_MOUSEBUTTONUP;
    if (opt & MSDL_MOUSEMOTION)
      type |= SDL_MOUSEMOTION;
    SDL_EventState(type, flags_state);
  }

  bool	*Event::get_keyboard() const
  {
    return ((bool *)m_keyboard);
  }

  bool	Event::get_key(SDLKey key) const
  {
    return ((bool)m_keyboard[(int)key]);
  }
}
