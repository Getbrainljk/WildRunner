#include "minisdl.hpp"
#include "Map.hpp"

class Images
{
public:
  Images(void);
  ~Images(void);
  msdl::Image *menu;
  msdl::Image *background;
  msdl::Image *win[6];
  msdl::Image *interface;
  msdl::Image *lumiere;
  msdl::Image *imageHuman;
  msdl::Image *imageHumanJump;
  msdl::Image *imageSouris;
  msdl::Image *imageSourisJump;
  msdl::Image *imageFelin;
  msdl::Image *imageFelinJump;
  msdl::Image *imageKangourou;
  msdl::Image *imageKangourouJump;
  msdl::Image *obstacle[Map::LAST_OBS];
  //  msdl::Image *porte[2];
  msdl::Sprite *spriteLumiere;
  msdl::Sprite *spriteHuman;
  msdl::Sprite *spriteHumanJump;
  msdl::Sprite *spriteSouris;
  msdl::Sprite *spriteSourisJump;
  msdl::Sprite *spriteFelin;
  msdl::Sprite *spriteFelinJump;
  msdl::Sprite *spriteKangourou;
  msdl::Sprite *spriteKangourouJump;
  //  msdl::Sprite *spritePorte[2];
};
