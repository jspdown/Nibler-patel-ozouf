//
// Floor.cpp for /home/vink/projet/cpp/Nibler-patel-ozouf/src/Event/Floor.cpp in /home/vink/projet/cpp/Nibler-patel-ozouf
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Thu Mar 21 17:09:34 2013 kevin platel
// Last update Thu Mar 21 19:21:16 2013 kevin platel
//


#include	"ActionEvent.hpp"
#include	"Trame.hh"
#include	"Floor.hh"

#include	"Debug.hh"

Floor::Floor(Rect *pos, int type, Map *map, Rect *tile) :
  AStaticEntity("floor", pos, type, map, tile)
{
}

Floor::~Floor()
{

}

Floor::Floor(const Floor &other):
  AStaticEntity(other)
{

}

void	Floor::update()
{

}

void	Floor::init()
{

}

Floor *Floor::clone(Rect *pos, int type, Map *map, Rect *r)	const
{
  return (new Floor(pos, type, map, r));
}

std::map<std::string, IActionEvent *> Floor::generateEventListened()
{
  std::map<std::string, IActionEvent *>	events;

  return (events);
}
