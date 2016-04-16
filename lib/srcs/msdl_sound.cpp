//
// msdl_sound.cpp for minisdl_cpp in /home/le-mai_s/librairie/minisdl_cpp/srcs/
//
// Made by sebastien le-maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Wed Nov 11 19:12:33 2015 sebastien le-maire
// Last update Mon Apr 18 23:26:17 2016 max eizenberg
//

#include "msdl_sound.hpp"

namespace	msdl
{
  void		init_channels(const int nb_channels)
  {
    Mix_AllocateChannels(nb_channels);
  }

  void		stop_playing_channel(const int channel)
  {
    Mix_HaltChannel(channel);
  }

  Sound::Sound()
  {
    m_sound = NULL;
  }

  Sound::~Sound()
  {
    if (m_sound)
      Mix_FreeChunk(m_sound);
  }

  bool		Sound::init(const char *name_sound)
  {
    if (!(m_sound = Mix_LoadWAV(name_sound)))
      return (false);
    return (true);
  }

  bool		Sound::play(const int loop, const int channel)
  {
    if (Mix_PlayChannel(channel, m_sound, loop) < 0)
      return (false);
    return (true);
  }
}
