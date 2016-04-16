//
// msdl_music.cpp for minisdl_cpp in /home/le-mai_s/librairie/minisdl_cpp/srcs/
//
// Made by sebastien le-maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Wed Nov 11 19:12:42 2015 sebastien le-maire
// Last update Wed Jan 27 15:18:17 2016 Sébastien Le Maire
//

#include "msdl_music.hpp"

namespace	msdl
{
  bool		activate_music(int frequency)
  {
    if (Mix_OpenAudio(frequency, MIX_DEFAULT_FORMAT,
		      MIX_DEFAULT_CHANNELS, 1024) == -1)
      return (false);
    return (true);
  }

  void		desactivate_music(void)
  {
    Mix_CloseAudio();
  }

  Music::Music()
  {
  }

  Music::~Music()
  {
    Mix_FreeMusic(m_music);
  }

  bool		Music::init(const char *name_music)
  {
    if (!(m_music = Mix_LoadMUS(name_music)))
      return (false);
    return (true);
  }

  bool		Music::play(const int loop)
  {
    if (Mix_PlayMusic(m_music, loop) < 0)
      return (false);
    return (true);
  }

  void		Music::pause(void) const
  {
    Mix_PauseMusic();
  }

  void		Music::resume(void) const
  {
    Mix_ResumeMusic();
  }

  void		Music::restart(void) const
  {
    Mix_RewindMusic();
  }

  bool		Music::volume(const unsigned char volume) const
  {
    if (volume > 128)
      return (false);
    Mix_VolumeMusic((int)volume);
    return (true);
  }

  void		Music::stop(void) const
  {
    Mix_HaltMusic();
  }

  bool		Music::is_playing(void) const
  {
    if (Mix_PlayingMusic() == 1)
      return (true);
    return (false);
  }

  bool		Music::is_paused(void) const
  {
    if (Mix_PausedMusic() == 1)
      return (true);
    return (false);
  }
}
