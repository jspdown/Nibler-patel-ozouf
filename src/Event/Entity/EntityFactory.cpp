//
// EntityFactory.cpp for /home/vink/projet/cpp/Nibler-patel-ozouf/src/Event/Entity/EntityFactory.cpp in /home/vink
//
// Made by vink
// Login   <kevin platel@epitech.net>
//
// Started on  Mon Mar 18 22:29:46 2013 vink
// Last update Fri Mar 22 19:36:55 2013 vink
//

#include <iostream>

#include "Wall.hh"
#include "Floor.hh"
#include "Food.hh"
#include "SnakePart.hh"
#include "Snake.hh"

#include "EntityFactory.hh"

EntityFactory::EntityFactory()
{
  this->learnEntity(new Snake(new Rect(), 0, 0, 0));
  this->learnEntity(new Wall(new Rect(), 0, 0, 0));
  this->learnEntity(new Floor(new Rect(), 0, 0, 0));
  this->learnEntity(new Food(new Rect(), 0, 0, 0));
}

EntityFactory::~EntityFactory()
{
  while (!(this->entity.empty()))
    {
      delete entity.front();
      entity.pop_front();
    }
}

void	EntityFactory::learnEntity(IEntity *n)
{
  if (std::find(this->entity.begin(), this->entity.end(), n) == this->entity.end())
    this->entity.push_back(n);
}

void	EntityFactory::unlearnEntity(IEntity *n)
{
  std::deque<IEntity*>::iterator it;
  if ((it = std::find(this->entity.begin(), this->entity.end(), n)) != this->entity.end())
    {
      this->entity.erase(it);
    }
}

IEntity*	EntityFactory::newEntity(std::string const &name, Rect *pos, int type, Map *map, Rect *tile)
{
  for (unsigned int i = 0; i < entity.size(); i++)
    {
      if (name == (entity[i])->getName())
	return (entity[i])->clone(pos, type, map, tile);
    }
  return (0);
}
