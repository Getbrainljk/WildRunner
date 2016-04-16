//
// Buffer.hpp for buffer in /home/le-mai_s/projet/ludum_dare_35/game
//
// Made by Sébastien Le Maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Mon Apr 18 14:38:54 2016 Sébastien Le Maire
// Last update Tue Apr 19 01:43:11 2016 Sébastien Le Maire
//

#ifndef BUFFER_HPP_
# define BUFFER_HPP_

#include <cstdlib>
#include <ctime>

namespace			Map
{
  enum				Elements
    {
				ERROR = -1,
				PYLONNE_1,
				PYLONNE_2,
				PYLONNE_3,
				WALL,
				ENTRE_TUBE,
				TUBE_MARRON,
				TUBE_MARRON2,
				TUBE_VERT,
				TUBE_VERT2,
				TUBE_BLEU,
				TUBE_BLEU2,
				LAST_OBS,
				BEGIN_SPRITE,
				PORTE_ROUGE,
				PORTE_BLEU,
				LAST_SPRITE,
				VOID,
				BLOCK_TUBE,
				BLOCK,
    };

  class				Buffer
  {
  public: /* ctor & dtor */
    Buffer();
    ~Buffer();

  public: /* Methods */
    void			swap(void);

  public: /* Operator */
    Map::Elements		operator[](unsigned short y);

  public: /* accessor */
    char       			getData(unsigned short x, unsigned short y) const;

  public: /* Algo */
    void			generation_obsable(unsigned short y);
    void			clear(void);

  private:
    Map::Elements      	        m_data[2][18];
    unsigned char		m_currentData;
    unsigned short int		m_genTubes;
  };
}

#endif /* !BUFFER_HPP_ */
