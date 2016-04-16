//
// msdl_screen.cpp for minisdl_cpp in /home/le-mai_s/librairie/minisdl_cpp/srcs
//
// Made by sebastien le-maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Mon Nov  9 21:55:03 2015 sebastien le-maire
// Last update Sat Apr 16 13:31:45 2016 Sébastien Le Maire
//

#include "msdl_screen.hpp"

namespace	msdl
{
  Screen::Screen()
  {
    m_surface = NULL;
    m_init_success = false;
  }

  Screen::~Screen()
  {
    if (m_surface)
      SDL_FreeSurface(m_surface);
    if (m_init_success)
      SDL_Quit();
  }

  bool		Screen::init(const unsigned char opt, const Uint16 width,
			     const Uint16 height, std::string title)
  {
    Uint32	flags;

    flags = SDL_INIT_VIDEO;
    if (opt & TIMER_ON)
      flags |= SDL_INIT_TIMER;
    if (opt & AUDIO_ON)
      flags |= SDL_INIT_AUDIO;
    if ((SDL_Init(flags) == -1))
      return (false);
    m_init_success = true;
    flags = (opt & OPENGL_ON) ? SDL_OPENGL : (SDL_HWSURFACE | SDL_DOUBLEBUF);
    if (opt & RESIZE_ON)
      flags |= SDL_RESIZABLE;
    else if (opt & FULLSCREEN_ON)
      flags |= SDL_FULLSCREEN;
    if (!(m_surface = SDL_SetVideoMode(width, height, 32, flags)))
      return (false);
    SDL_WM_SetCaption((const char *)title.c_str(), NULL);
    if (SDL_FillRect(m_surface, NULL, SDL_MapRGB(m_surface->format, 0, 0, 0)))
      return (false);
    SDL_Flip(m_surface);
    return (true);
  }

  void		Screen::set_icon(Image &icon)
  {
    SDL_WM_SetIcon(icon.get_surface(), NULL);
  }

  void		Screen::update(void) const
  {
    SDL_Flip(m_surface);
  }

  void		Screen::blit(Image const &image, const Uint16 x,
			     const Uint16 y, SDL_Rect const *rect_src)
  {
    SDL_Rect	pos;

    pos.x = x;
    pos.y = y;
    pos.w = m_surface->w;
    pos.h = m_surface->h;
    SDL_BlitSurface(image.get_surface(), const_cast<SDL_Rect *>(rect_src),
		    m_surface, &pos);
  }

  void		Screen::blit(Font const &font, const Uint16 x,
			     const Uint16 y, SDL_Rect const *rect_src)
  {
    SDL_Rect	pos;

    pos.x = x;
    pos.y = y;
    pos.w = m_surface->w;
    pos.h = m_surface->h;
    SDL_BlitSurface(font.get_surface(), const_cast<SDL_Rect *>(rect_src),
		    m_surface, &pos);
  }

  bool		Screen::switch_fullscreen(void)
  {
    SDL_Surface	*screen;
    Uint32	flags;

    if (!(screen = SDL_GetVideoSurface()))
      return (false);
    flags = (screen->flags ^ SDL_FULLSCREEN);
    if (!(screen = SDL_SetVideoMode(0, 0, 0, flags)))
      return (false);
    SDL_FreeSurface(m_surface);
    m_surface = screen;
    return (true);
  }

  bool		Screen::switch_resize(void)
  {
    SDL_Surface	*screen;
    Uint32	flags;

    if (!(screen = SDL_GetVideoSurface()))
      return (false);
    flags = (screen->flags ^ SDL_RESIZABLE);
    if (!(screen = SDL_SetVideoMode(0, 0, 0, flags)))
      return (false);
    SDL_FreeSurface(m_surface);
    m_surface = screen;
    return (true);
  }

  /*
  ** Static function associate to screen
  */

  bool	        Screen::init_system(const unsigned char opt)
  {
    Uint32	flags;

    flags = ALL_OFF;
    if (opt & TIMER_ON)
      flags |= SDL_INIT_TIMER;
    if (opt & AUDIO_ON)
      flags |= SDL_INIT_AUDIO;
    if (SDL_InitSubSystem(flags) == -1)
      return (false);
    return (true);
  }

  void		Screen::quit_system(const unsigned char opt)
  {
    Uint32	flags;

    flags = ALL_OFF;
    if (opt & TIMER_ON)
      flags |= SDL_INIT_TIMER;
    if (opt & AUDIO_ON)
      flags |= SDL_INIT_AUDIO;
    SDL_QuitSubSystem(flags);
  }
}
