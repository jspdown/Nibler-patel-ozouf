//
// Food.cpp for /home/vink/projet/cpp/Nibler-patel-ozouf/src/Event/Food.cpp in /home/vink/projet/cpp/Nibler-patel-ozouf
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Thu Mar 21 19:20:33 2013 kevin platel
// Last update Thu Mar 21 19:21:48 2013 kevin platel
//

#include	"ActionEvent.hpp"
#include	"Trame.hh"
#include	"Food.hh"

#include	"Debug.hh"

Food::Food(Rect *pos, int type, Map *map, Rect *tile) :
  AStaticEntity("food", pos, type, map, tile)
{
}

Food::~Food()
{

}

Food::Food(const Food &other):
  AStaticEntity(other)
{

}

void	Food::update()
{

}

void	Food::init()
{

}

Food *Food::clone(Rect *pos, int type, Map *map, Rect *r)	const
{
  return (new Food(pos, type, map, r));
}

std::map<std::string, IActionEvent *> Food::generateEventListened()
{
  std::map<std::string, IActionEvent *>	events;

  return (events);
}
