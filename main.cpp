
#include "Environment.hpp"

bool            victory_loop(msdl::Screen &screen, void *param)
{
    Environment *env = static_cast<Environment *>(param);
    static int  slow = 0;
    static int chrono = SDL_GetTicks();
    int time = SDL_GetTicks() - chrono;
    std::ostringstream stream;

    if (env->event.get_key(SDLK_RETURN))
        env->back_to_menu();
    screen.clear();
    screen.blit(*(env->images->win[slow]));
    if (time > 400)
    {
        ++slow;
        chrono = SDL_GetTicks();
    }
    if (slow > 5)
      slow = 0;
    screen.update();
    return (true);
}

bool	    	game_loop(msdl::Screen &screen, void *param)
{
    Environment *env = static_cast<Environment *>(param);
    static int	decObs = 0;
    static int	columns = 0;

    if (env->chronoMode)
    {
        if (!env->character->is_alive())
        {
            env->startingTime = SDL_GetTicks();
            env->character->live();
        }
        if ((env->currentTime = SDL_GetTicks() - env->startingTime) >= TIME_TO_WIN)
        {
            env->event.set_fct_loop(victory_loop);
            return (true);
        }
    }
    screen.clear();
    env->display_scene(screen);
    env->display_score(screen);
    if (env->chronoMode)
        env->display_chrono(screen);
    if (decObs == 5)
    {
      decObs = 0;
      for (int i = 0; i < 17; ++i)
        env->map[i] = env->map[i + 1];
      env->map[17] = env->buffer[columns];
      ++columns;
      if (columns == 18)
        {
            columns = 0;
            env->buffer.swap();
        }
    }
    else
        ++decObs;

    for (int i = 0; i < 18; ++i)
    {
        if ((env->map[i] >= Map::PYLONNE_1) && (env->map[i] < Map::LAST_OBS))
            screen.blit(*(env->images->obstacle[env->map[i]]),
		    ((50 * i) - (decObs * 10)),
		    825 - env->images->obstacle[env->map[i]]->height());
        if ((env->map[i] >= Map::ENTRE_TUBE && env->map[i] < Map::LAST_OBS) || (env->map[i] == Map::BLOCK_TUBE))
        {
            for (unsigned short z = 0; z < 15; ++z)
            {
                screen.blit(*(env->images->obstacle[Map::WALL]),
                ((50 * i) - (decObs * 10)), 50 * z + 25);
            }
        }
    }

    env->character->jump(env->event, env->map);
    env->character->shift(screen, env->event, env->wildsound, env->images, env->map);
    if (env->character->is_dead(env->wildsound, env->map))
    {
        decObs = 0;
        columns = 0;
        env->back_to_menu();
        return (true);
    }
    env->character->display(screen);
    screen.update();
    return (true);
}

bool			menu_loop(msdl::Screen &screen, void *param)
{
    Environment		*env = static_cast<Environment *>(param);
    Menu::Button		**button = &env->button[0];
    std::ostringstream stream;

    stream << "Last score : " << env->score;
    screen.clear();
    screen.blit(*(env->images->menu), 0, 0, 0);
    screen.blit(*(env->images->interface), 0, 0, 0);
    env->font.write<std::string>("Wild runner", screen.get_surface(), msdl::Font::t_type::SOLID, 300, 400, 0x000000);
    env->font.write<std::string>(stream.str(), screen.get_surface(), msdl::Font::t_type::SOLID, 300, 500);
    for (unsigned short i = 0; i < 3; ++i)
        button[i]->putOnSurface(screen);
    screen.update();
    env->character->reset();
    return (true);
}

int			main(int, char **)
{
  msdl::Screen		screen;
  msdl::Font::init_ttf();
  Environment		env;

  if (screen.init(FULLSCREEN_ON, 900, 900, "WILD RUNNER"))
    {
      env.wildsound->GoPlayLoop("./Sound/Sound/ZoneSound/DwarfTavern3modified.wav", env.wildsound->musique, 120);
      if ((!(env.button[0] = new Menu::Button("ENDLESS", env.font, 50, 730, 250, 100,
					      0x000000, 0xC7C7C7, 0xFF6600))) ||
	  (!(env.button[1] = new Menu::Button("CHRONO", env.font, 350, 730, 250, 100,
					      0x000000, 0xC7C7C7, 0xFF6600))) ||
	  (!(env.button[2] = new Menu::Button("QUIT", env.font, 650, 730, 200, 100,
					      0x000000, 0xC7C7C7, 0xFF6600))))
        return (EXIT_FAILURE);
      env.event.set_key(keyEvent);
      env.event.set_mouse(mousePress, NULL, mouseMotion);
      env.event.set_fct_loop(menu_loop);
      env.event.loop(screen, &env);

      for (unsigned short i = 0; i < 3; ++i)
	delete env.button[i];
    }
  return (EXIT_SUCCESS);
}
