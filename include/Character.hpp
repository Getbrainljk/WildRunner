//
// Created by Augustin Saint Olive on 16/04/2016.
//

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <cmath>
#include "data.hpp"
#include "Map.hpp"
#include "Images.hpp"
#include "SoundOfTheWild.hpp"

typedef struct	type_s
{
  int		xSize;
  int		ySize;
  int		speed;
  int		jump;
  int		jump_max;
  msdl::Sprite	*i_normal;
  msdl::Sprite	*i_jump;
  const char	*cry;
}		type;

struct			obstacle_type
{
  enum Map::Elements	id;
  int			size;
};

class Character
{
public:
  Character(const Images *);
  ~Character(void) { };

  void    reset(void);
  void    jump(const msdl::Event &, const Map::Elements *);
  void    shift(msdl::Screen &, const msdl::Event &, SoundOfTheWild *, const Images *, const Map::Elements *);
  bool    is_dead(SoundOfTheWild *, const Map::Elements *);
  bool    is_alive(void) const { return (life); }
  void    live(void) { life = true; }
  void    display(msdl::Screen &);
  
private:
  enum Forme : int
  {
    HUMAN,
      SPEED,
      JUMPER,
      GROUND
      };

  void    to_human(void) { actual = HUMAN; }
  void    to_speed(void) { actual = SPEED; }
  void    to_jumper(void) { actual = JUMPER; }
  void    to_ground(void) { actual = GROUND; }
  int     collision(int);

  bool    life;
  bool    jumping;
  bool    falling;
  int     x;
  int     y;
  Forme   actual;
  type    forme[4];
};

#endif //CHARACTER_HPP
