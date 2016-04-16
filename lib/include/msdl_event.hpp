/*
** msdl_event.h for minisdl in /home/le-mai_s/librairie/minisdl_cpp
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Sat Jan  2 20:48:26 2016 sebastien le-maire
** Last update Wed Jan 27 15:13:36 2016 Sébastien Le Maire
*/

#ifndef MSDL_EVENT_HPP_
# define MSDL_EVENT_HPP_

# include "msdl_screen.hpp"
# include "msdl_macro.hpp"

/*
** Param of events functions
*/
# define KEY_PARAM_EVENT	msdl::Screen &, SDLKey, SDLMod, void *
# define MOUSE_PARAM_EVENT      msdl::Screen &, Uint8, Uint16 *, void *
# define MOTION_PARAM_EVENT	msdl::Screen &, Uint16, Uint16, void *
# define FCT_LOOP_PARAM_EVENT	msdl::Screen &, void *

namespace	msdl
{
  class		Event
  {
  public:
    Event();
    ~Event();
    void	set_key(bool (*keypress)(KEY_PARAM_EVENT),
			bool (*keyrelease)(KEY_PARAM_EVENT) = NULL);
    void	set_mouse(bool (*mousepress)(MOUSE_PARAM_EVENT),
			  bool (*mouserelease)(MOUSE_PARAM_EVENT) = NULL,
			  bool (*mousemotion)(MOTION_PARAM_EVENT) = NULL);
    void	set_fct_loop(bool (*fct_loop)(FCT_LOOP_PARAM_EVENT));
    void	set_ogl(bool (*fct_ogl)(void *));
    void        loop(msdl::Screen &screen, void *param = NULL,
		     Uint32 frame = 33);
    void	state(const unsigned char opt = MSDL_ALL_EVENT,
		      const bool state_enable = true);
    bool	*get_keyboard() const;
    bool	get_key(SDLKey key) const;

  private:
    bool		m_continu;
    SDL_Event		m_event;
    Uint32		m_time[2];
    bool		(*m_key[2])(KEY_PARAM_EVENT);
    bool		(*m_mouse[2])(MOUSE_PARAM_EVENT);
    bool		(*m_motion)(MOTION_PARAM_EVENT);
    bool		(*m_fct_loop)(FCT_LOOP_PARAM_EVENT);
    bool		(*m_fct_ogl)(void *);
    bool		m_keyboard[SDLK_LAST];
    void		event(msdl::Screen &screen, void *param);
    bool		key(msdl::Screen &screen, void *param,
			    const Uint8 index);
    bool		mouse(msdl::Screen &screen, void *param,
			      const Uint8 index);
    bool		motion(msdl::Screen &screen, void *param);
  };
}

#endif /* !MSDL_EVENT_HPP_ */
