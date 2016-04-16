/*
** msdl_sound.h for minisdl_cpp in /home/le-mai_s/librairie/minisdl_cpp/include/
**
** Made by sebastien le-maire
** Login   <le-mai_s@epitech.net>
**
** Started on  Wed Nov 11 19:08:56 2015 sebastien le-maire
// Last update Mon Apr 18 23:19:35 2016 max eizenberg
*/

#ifndef MSDL_SOUND_HPP_
# define MSDL_SOUND_HPP_

# include <SDL/SDL.h>
# include <SDL/SDL_mixer.h>

namespace	msdl
{
  class	Sound
  {
  public:
    Sound();
    ~Sound();

    bool	init(const char *name_sound);

    bool	play(const int loop = 0, const int channel = -1);

  private:
    Mix_Chunk	*m_sound;
  };

  void		init_channels(const int nb_channels);

  void	        stop_playing_channel(const int channel = -1);
}

#endif /* !MSDL_SOUND_HPP_ */
