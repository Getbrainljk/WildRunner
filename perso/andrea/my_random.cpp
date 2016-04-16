//
// my_random.cpp for my_random in /home/messin_b/game/andrea
// 
// Made by andrea messines
// Login   <messin_b@epitech.net>
// 
// Started on  Sat Apr 16 15:36:35 2016 andrea messines
// Last update Sat Apr 16 16:40:08 2016 andrea messines
//

#include <iostream>
#include <random>

int old;
int	r = 0;

char	*my_random()
{
  char *tab = new char[19];
  int	n;
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<> dis(1, 7);
  tab[18] = '\0';
  n = -1;
  while (n++ != 17)
    tab[n] = 'a';
  n = dis(gen);
  if (old == 5)
    {
      if (n < 3 && r < 5)
	{
	  old = 5;
	  tab[17] = 't';
	  r++;
	  return (tab);
	}
      else
	{
	  r = 0;
	  old = 6;
	  return (tab);
	}
    }
  else if (old == 6)
    {
      old = n;
      if (n == 1)
	{
	  tab[15] = 'd';
	  tab[16] = 'd';
	  tab[17] = 'd';
	}
      else if (n == 2)
	{
	  tab[15] = 'c';
	  tab[16] = 'c';
	  tab[17] = 'c';
	}
      else
	{
	  tab[14] = 'p';
	  tab[15] = 'p';
	  tab[16] = 'p';
	  tab[17] = 'p';
	}
      return (tab);
    }
  else
    old = 6;
  return (tab);
}

int main()
{
  old = 0;
  std::cout << my_random() << std::endl;
  std::cout << my_random() << std::endl;
  std::cout << my_random() << std::endl;
  std::cout << my_random() << std::endl;
  std::cout << my_random() << std::endl;
  std::cout << my_random() << std::endl;
  std::cout << my_random() << std::endl;
  std::cout << my_random() << std::endl;
  std::cout << my_random() << std::endl;
  std::cout << my_random() << std::endl;
  std::cout << my_random() << std::endl;
  std::cout << my_random() << std::endl;
  std::cout << my_random() << std::endl;
  std::cout << my_random() << std::endl;
  std::cout << my_random() << std::endl;
  std::cout << my_random() << std::endl;
  std::cout << my_random() << std::endl;
  std::cout << my_random() << std::endl;
  std::cout << my_random() << std::endl;
  std::cout << my_random() << std::endl;
  std::cout << my_random() << std::endl;
  std::cout << my_random() << std::endl;
  std::cout << my_random() << std::endl;
  std::cout << my_random() << std::endl;
  std::cout << my_random() << std::endl;
  std::cout << my_random() << std::endl;
}
