#include "Environment.hpp"

bool			keyEvent(msdl::Screen &, SDLKey key, SDLMod , void *)
{
  if (key == SDLK_ESCAPE)
    return (false);
  return (true);
}

bool			mouseMotion(msdl::Screen &, Uint16 x, Uint16 y, void *param)
{
  Menu::Button		**button = &static_cast<Environment *>(param)->button[0];

  for (unsigned short i = 0; i < 3; ++i)
    button[i]->checkOnOff(x, y);
  return (true);
}

bool			mousePress(msdl::Screen &, Uint8, Uint16 *mouse, void *param)
{
  Environment		*env = static_cast<Environment *>(param);
  Menu::Button		**button = &env->button[0];

  if (button[0]->push(mouse[0], mouse[1]))
    {
      env->chronoMode = false;
      env->event.set_mouse(NULL);
      env->event.set_fct_loop(game_loop);
      env->wildsound->GoPlayLoop("Sound/Sound/ZoneSound/Run.wav", env->wildsound->musique2, 60);
    }
  if (button[1]->push(mouse[0], mouse[1]))
    {
      env->chronoMode = true;
      env->event.set_mouse(NULL);
      env->event.set_fct_loop(game_loop);
      env->wildsound->GoPlayLoop("Sound/Sound/ZoneSound/Run.wav", env->wildsound->musique2, 60);
    }
  if (button[2]->push(mouse[0], mouse[1]))
    return (false);
  return (true);
}

Environment::Environment(void)
{
  x = 0;
  score = 0;
  font.load("Police/Celtic.ttf");
  for (int i = 0; i < 18; ++i)
    map[i] = buffer[i];
  images = new Images;
  wildsound = new SoundOfTheWild;
  character = new Character(images);
}

Environment::~Environment(void)
{
    delete character;
    delete wildsound;
    delete images;
}

void    Environment::reset(void)
{
    x = 0;
    score = 0;
    for (int i = 0; i < 18; ++i)
        map[i] = Map::VOID;
    buffer.clear();
}

void    Environment::back_to_menu(void)
{
    event.set_mouse(mousePress, NULL, mouseMotion);
    event.set_fct_loop(menu_loop);
    wildsound->GoPlayLoop("Sound/Sound/ZoneSound/DwarfTavern3modified.wav", wildsound->musique, 120);
}

void            Environment::display_scene(msdl::Screen &screen)
{
  SDL_Rect    rec1;
  SDL_Rect    rec2;

  rec1.x = x;
  rec1.y = 0;
  rec1.w = 900 - x;
  rec1.h = 900;
  rec2.x = 0;
  rec2.y = 0;
  rec2.w = x;
  rec2.h = 900;
  screen.blit(*(images->background), 0, 0, &rec1);
  screen.blit(*(images->background), 900 - x, 0, &rec2);
  x += 5;
  if (x > 900)
    x = 0;
}

void    Environment::display_score(msdl::Screen &screen)
{
    std::ostringstream stream;

    stream << "Score : " << score;
    score += 1;
    font.write<std::string>(stream.str(), screen.get_surface(), msdl::Font::t_type::SOLID, 300, 100);
}

void    Environment::display_chrono(msdl::Screen &screen)
{
    std::ostringstream stream;
    long time = SDL_GetTicks() - startingTime;
    long secondes = time / 1000;
    long minutes = secondes / 60;

    stream << std::setfill ('0') << std::setw(2) << 1 - minutes << ":" << std::setfill ('0') << std::setw(2) << 59 - (secondes % 60);
    font.write<std::string>(stream.str(), screen.get_surface(), msdl::Font::t_type::SOLID, 100, 100);
}
