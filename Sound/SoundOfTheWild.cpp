
# include "SoundOfTheWild.hpp"
# include "msdl_sound.hpp"
# include "msdl_music.hpp"

SoundOfTheWild :: SoundOfTheWild ()
{
  son = new msdl::Sound;
  son2 = new msdl::Sound;
  musique = new msdl::Music;
  musique2 = new msdl::Music;
}

SoundOfTheWild :: ~SoundOfTheWild()
{}

void	// music restart  (pas d'appel à désactivate_music()
SoundOfTheWild :: GoPlayLoop(const char *music, msdl::Music *ptr, unsigned int nb)
{
  if (!(msdl::activate_music()))
    return ;
  if (!(ptr->init(music)))
    return ;
  ptr->volume(nb);
  ptr->play();
}

void      // play sound with object music
SoundOfTheWild :: GoPlayCry(const char *music, msdl::Music *ptr)
{
  if (!(msdl::activate_music()))
    return ;
  if (!(ptr->init(music)))
    return ;
  ptr->volume(60);
  ptr->play();
}

void     // play sound with object sound
SoundOfTheWild :: GoPlayCry(const char *sound, msdl::Sound *ptr, const int chan)
{
  msdl::init_channels(chan);
  ptr->init(sound);
  ptr->play();
  //  msdl::stop_playing_channel();
}
