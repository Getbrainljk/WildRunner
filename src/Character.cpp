//
// Created by Augustin Saint Olive on 16/04/2016.
//

#include "Character.hpp"

Character::Character(const Images *images) {
    life = false;
    jumping = false;
    falling = false;
    x = INIT_CHARACTER_X;
    y = INIT_CHARACTER_Y;
    actual = HUMAN;

    forme[HUMAN].speed = 3;
    forme[SPEED].speed = 2;
    forme[JUMPER].speed = 6;
    forme[GROUND].speed = 4;

    forme[HUMAN].xSize = 30;
    forme[SPEED].xSize = 60;
    forme[JUMPER].xSize = 30;
    forme[GROUND].xSize = 10;

    forme[HUMAN].ySize = 150;
    forme[SPEED].ySize = 100;
    forme[JUMPER].ySize = 150;
    forme[GROUND].ySize = 50;

    forme[HUMAN].jump = HUMAN_J;
    forme[SPEED].jump = SPEED_J;
    forme[JUMPER].jump = JUMPER_J;
    forme[GROUND].jump = GROUND_J;

    forme[HUMAN].jump_max = HUMAN_J * GRAVITY;
    forme[SPEED].jump_max = SPEED_J * GRAVITY;
    forme[JUMPER].jump_max = JUMPER_J * GRAVITY;
    forme[GROUND].jump_max = GROUND_J * GRAVITY;

    forme[HUMAN].i_normal = images->spriteHuman;
    forme[SPEED].i_normal = images->spriteFelin;
    forme[JUMPER].i_normal = images->spriteKangourou;
    forme[GROUND].i_normal = images->spriteSouris;

    forme[HUMAN].i_jump = images->spriteHumanJump;
    forme[SPEED].i_jump = images->spriteFelinJump;
    forme[JUMPER].i_jump = images->spriteKangourouJump;
    forme[GROUND].i_jump = images->spriteSourisJump;

    forme[HUMAN].cry = "Sound/Sound/CreaturesSound/meuf/HumanFemaleKidCry1.wav";
    forme[SPEED].cry = "Sound/Sound/CreaturesSound/tiger/mTigerDeathA.wav";
    forme[JUMPER].cry = "Sound/Sound/CreaturesSound/kangourou/WightDeath.wav";
    forme[GROUND].cry = "Sound/Sound/CreaturesSound/rat/RatDeathA.wav";
}

void    Character::reset(void)
{
    life = false;
    x = INIT_CHARACTER_X;
    y = INIT_CHARACTER_Y;
    actual = HUMAN;
}

void    Character::jump(const msdl::Event &event, const Map::Elements *map)
{
    int			obstacle[19] = {300, 300, 300, 50, 0, 0, 0, 0, 0, 0, 0, -1, -1, 150, 150, -1, 0, 800, 0};

    if (!jumping && obstacle[map[x / 50]] < y)  //présence de vide
        falling = true;
    else if (event.get_key(SDLK_SPACE)) //activation du saut
        jumping = true;
    if (jumping)    //ascension
    {
      y += -1 * sqrt(forme[actual].jump) / 3 + 10;
      if (y > forme[actual].jump_max)
        {
            jumping = false;
            falling = true;
        }
    }
    else if (falling && y > obstacle[map[x / 50]]) //descente
    {
      y -= -1 * sqrt(forme[actual].jump) / 3 + 10;
      if (y < obstacle[map[x / 50]])
        {
            falling = false;
            y = obstacle[map[x / 50]];
        }
    }
}

void    Character::shift(msdl::Screen &screen, const msdl::Event &event, SoundOfTheWild *wildsound, const Images *images, const Map::Elements *map)
{
  if ((event.get_key(SDLK_a) || event.get_key(SDLK_q) || event.get_key(SDLK_u)) && actual != GROUND && (map[x / 50] < 4 || map[x / 50] > 10) && map[x / 50] != 17)
    {
      wildsound->GoPlayCry("./Sound/Sound/CreaturesSound/rat/RatWoundA.wav", wildsound->son, 1);
      screen.blit(images->spriteLumiere->getImage(), x - 70, GROUND_LEVEL - 200 - y, images->spriteLumiere->getRectSprite());
      images->spriteLumiere->nextSprite();
      images->spriteLumiere->nextSprite();
      to_ground();
    }
  if ((event.get_key(SDLK_z) || event.get_key(SDLK_w) || event.get_key(SDLK_i)) && actual != SPEED && (map[x / 50] < 4 || map[x / 50] > 10) && map[x / 50] != 17)
    {
      wildsound->GoPlayCry("Sound/Sound/CreaturesSound/tiger/mTigerAttackA.wav", wildsound->son, 1);
      screen.blit(images->spriteLumiere->getImage(), x - 70, GROUND_LEVEL - 200 - y, images->spriteLumiere->getRectSprite());
      images->spriteLumiere->nextSprite();
      images->spriteLumiere->nextSprite();
      to_speed();
    }
  if ((event.get_key(SDLK_e) || event.get_key(SDLK_o)) && actual != JUMPER && (map[x / 50] < 4 || map[x / 50] > 10) && map[x / 50] != 17)
    {
      wildsound->GoPlayCry("Sound/Sound/CreaturesSound/kangourou/WightAttackA.wav", wildsound->son, 1);
      screen.blit(images->spriteLumiere->getImage(), x - 70, GROUND_LEVEL - 200 - y, images->spriteLumiere->getRectSprite());
      images->spriteLumiere->nextSprite();
      images->spriteLumiere->nextSprite();
      to_jumper();
    }
  if ((event.get_key(SDLK_r) || event.get_key(SDLK_p)) && actual != HUMAN && (map[x / 50] < 4 || map[x / 50] > 10) && map[x / 50] != 17)
    {
      wildsound->GoPlayCry("Sound/Sound/CreaturesSound/meuf/HumanFemaleKidCry1.wav", wildsound->son, 1);
      screen.blit(images->spriteLumiere->getImage(), x - 70, GROUND_LEVEL - 200 - y, images->spriteLumiere->getRectSprite());
      images->spriteLumiere->nextSprite();
      images->spriteLumiere->nextSprite();
      to_human();
    }
}

int    Character::collision(int obstacle)
{
  struct obstacle_type o[] = {
    {Map::PYLONNE_1,300},
    {Map::PYLONNE_2,300},
    {Map::PYLONNE_3,300},
    {Map::WALL,50},
    {Map::ENTRE_TUBE,800},
    {Map::TUBE_MARRON,800},
    {Map::TUBE_MARRON2,800},
    {Map::TUBE_VERT,800},
    {Map::TUBE_VERT2,800},
    {Map::TUBE_BLEU,800},
    {Map::TUBE_BLEU2,800},
    {Map::LAST_OBS,-1},
    {Map::BEGIN_SPRITE,-1},
    {Map::PORTE_ROUGE,150},
    {Map::PORTE_BLEU,150},
    {Map::LAST_SPRITE,-1},
    {Map::VOID, -1},
    {Map::BLOCK_TUBE,800},
    {Map::BLOCK, -1}
  };

  if ((obstacle == 3 && y < o[3].size) ||
      (obstacle == 0 && y < o[0].size) ||
      (obstacle == 1 && y < o[1].size) ||
      (obstacle == 2 && y < o[2].size) ||
      (obstacle == 5 && actual != GROUND) ||
      (obstacle == 6 && actual != GROUND) ||
      (obstacle == 7 && actual != GROUND) ||
      (obstacle == 8 && actual != GROUND) ||
      (obstacle == 9 && actual != GROUND) ||
      (obstacle == 10 && actual != GROUND) ||
      (obstacle == 17 && actual != GROUND)
      /*
      obstacle == 13 && player_y < o[13].size ||
      obstacle == 14 && player_y < o[14].size ||
      obstacle == 17 && player_y < o[17].size*/
      )
    x -= DEPLACEMENT;
  return (x);
}

bool    Character::is_dead(SoundOfTheWild *wildsound, const Map::Elements *map)
{
  if ((x = collision(map[x / 50 + 1])) < 0)
    {
      wildsound->GoPlayCry(forme[actual].cry, wildsound->son2, 1);
      life = false;
      return (true);
    }
  return (false);
}

void    Character::display(msdl::Screen &screen)
{
  if (jumping || falling)
    {
      screen.blit(forme[actual].i_jump->getImage(), x, GROUND_LEVEL - forme[actual].ySize - y, forme[actual].i_jump->getRectSprite());
      forme[actual].i_jump->nextSprite();
    }
  else
    {
      screen.blit(forme[actual].i_normal->getImage(), x, GROUND_LEVEL - forme[actual].ySize - y, forme[actual].i_normal->getRectSprite());
      forme[actual].i_normal->nextSprite();
    }
}
