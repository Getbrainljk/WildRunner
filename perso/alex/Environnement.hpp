
#ifndef		ENVIRONNEMENT_H
# define	ENVIRONNEMENT_H

/*
** Class
*/

class Environnement
{
public:

  //ctor & dtor
  Environnement();
  ~Environnement();

  void	ciel();
  // sol pour la taupe
  void	sol();
  void	luminosite();
  void	temps();
  // nuit ou jour
  void	etat_jour();

};

#endif      /* !ENVIRONNEMENT_H_ */
