#ifndef		OBSTACLE_H
# define	OBSTACLE_H

/*
** Class
*/

class Obstacle	: public  Environnement
{
public:

  //ctor & dtor
  Obstacle();
  ~Obstacle();

  // à deter
  int obstacles;
};

#endif      /* !OBSTACLE_H_ */
