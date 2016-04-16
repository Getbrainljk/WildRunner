/*
** msdl_music.h for minisdl_cpp in /home/le-mai_s/librairie/minisdl_cpp/include/
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Wed Nov 11 19:08:19 2015 sebastien le-maire
** Last update Wed Jan 27 15:18:45 2016 Sébastien Le Maire
*/

#ifndef MSDL_MUSIC_HPP_
# define MSDL_MUSIC_HPP_

# include <SDL/SDL.h>
# include <SDL/SDL_mixer.h>
# include "msdl_macro.hpp"

namespace	msdl
{
  bool		activate_music(int frequency = CD_QUALITY);
  void		desactivate_music(void);

  class	Music
  {
  public:
    Music();
    ~Music();

    bool	init(const char *name_music);

    bool	play(const int loop = AUDIO_LOOP_INF);

    void	pause(void) const;

    void        resume(void) const;

    void        restart(void) const;

    bool        volume(const unsigned char volume) const;

    void        stop(void) const;

    bool	is_playing(void) const;

    bool	is_paused(void) const;

  private:
    Mix_Music	*m_music;
  };
}

#endif /* !MSDL_MUSIC_HPP_ */
