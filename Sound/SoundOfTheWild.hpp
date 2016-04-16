
#ifndef		SOUNDOFTHEWILD_H
# define	SOUNDOFTHEWILD_

# include "msdl_sound.hpp"
# include "msdl_music.hpp"

class SoundOfTheWild
{
public:

  msdl::Sound	*son;
  msdl::Sound	*son2;
  msdl::Music	*musique;
  msdl::Music	*musique2;

  //ctor & dtor
  SoundOfTheWild();
  ~SoundOfTheWild();

  void
  GoPlayLoop(const char *music, msdl::Music *ptr, unsigned int nb);
  void
  GoPlayCry(const char *music, msdl::Music *ptr);
  void
  GoPlayCry(const char *sound, msdl::Sound *ptr, const int chan);

};

#endif      /* !SOUNDOFTHEWILD_H_ */
