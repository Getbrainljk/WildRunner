//
// Buffer.cpp for Buffer in /home/le-mai_s/projet/ludum_dare_35/game
//
// Made by Sébastien Le Maire
// Login   <le-mai_s@epitech.net>
//
// Started on  Mon Apr 18 14:39:00 2016 Sébastien Le Maire
// Last update Tue Apr 19 02:29:30 2016 Sébastien Le Maire
//

#include "Map.hpp"

namespace			Map
{
  Buffer::Buffer() : m_currentData(0), m_genTubes(0)
  {
    unsigned short		i;

    for (i = 0; i < 2; ++i)
      {
	unsigned short		j;

	for (j = 0; j < 18; ++j)
	  m_data[i][j] = Map::VOID;
      }
  }

  Buffer::~Buffer()
  {
  }

  /*
  ** Methods
  */

  void				Buffer::swap(void)
  {
    srand(time(NULL));
    this->m_currentData = !this->m_currentData;
  }

  void				Buffer::generation_obsable(unsigned short y)
  {
    Map::Elements		lastObs = ((y) ? this->m_data[!this->m_currentData][y - 1] :
					   this->m_data[this->m_currentData][17]);
    int				elem;
    static int			spaceVoid = 0;

    if (spaceVoid > 0)
      {
	elem = static_cast<int>(Map::VOID);
	--spaceVoid;
      }
    else if (this->m_genTubes > 0)
      {
	if (lastObs == static_cast<int>(Map::BLOCK_TUBE))
	  {
	    --(this->m_genTubes);
	    if (!this->m_genTubes)
	      spaceVoid = 15;
	    elem = (rand() % 6) + (static_cast<int>(Map::ENTRE_TUBE) + 1);
	  }
	else
	  elem = static_cast<int>(Map::BLOCK_TUBE);
      }
    else if (lastObs == Map::VOID)
      {
        while (((elem = rand() % (static_cast<int>(Map::VOID) + 1)) == Map::LAST_OBS) ||
	       (elem == Map::BEGIN_SPRITE) || (elem == Map::LAST_SPRITE) ||
	       ((elem > ENTRE_TUBE) && (elem < LAST_OBS)));
        if (elem == static_cast<int>(Map::ENTRE_TUBE))
        this->m_genTubes = ((rand() % 5) + 4);
      }
    else if (lastObs > static_cast<int>(VOID))
      elem = static_cast<int>(VOID);
    else
      {
        elem = ((lastObs > static_cast<int>(Map::ENTRE_TUBE)) &&
		(lastObs <= static_cast<int>(Map::TUBE_BLEU2))) ?
        static_cast<int>(BLOCK_TUBE) : static_cast<int>(BLOCK);
        spaceVoid = 13;
      }
    this->m_data[!this->m_currentData][y] = static_cast<Map::Elements>(elem);
  }


  Map::Elements			Buffer::operator[](unsigned short y)
  {
    if (y >= 18)
      return (Map::ERROR);
    generation_obsable(y);
    return (this->m_data[this->m_currentData][y]);
  }

  void				Buffer::clear(void)
  {
    for (unsigned short i = 0; i < 2; ++i)
      {
        for (unsigned short j = 0; j < 18; ++j)
            m_data[i][j] = Map::VOID;
      }
  }
}
