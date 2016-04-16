#ifndef		ENVIRONNEMENT_HPP_
# define	ENVIRONNEMENT_HPP_

# include "SoundOfTheWild.hpp"
# include "Character.hpp"
# include "Button.hpp"

bool			keyEvent(msdl::Screen &, SDLKey, SDLMod , void *);
bool			mouseMotion(msdl::Screen &, Uint16, Uint16, void *);
bool			mousePress(msdl::Screen &, Uint8, Uint16 *, void *);
bool			menu_loop(msdl::Screen &, void *);
bool	   		game_loop(msdl::Screen &screen, void *param);

class Environment
{
public:
  Environment(void);
  ~Environment(void);

  bool    gameLoop(msdl::Screen &screen, void *param);
  void    reset(void);
  void    back_to_menu(void);
  void    display_scene(msdl::Screen &);
  void    display_score(msdl::Screen &);
  void    display_chrono(msdl::Screen &);

  msdl::Event		event;
  msdl::Font		font;
  SoundOfTheWild	*wildsound;
  Images		*images;
  Character		*character;
  
  bool			chronoMode;
  long			startingTime;
  long			currentTime;
  int			x;
  long			score;
  Menu::Button		*button[3];
  Map::Buffer		buffer;
  Map::Elements		map[18];

};

#endif      /* !ENVIRONNEMENT_HPP_ */
