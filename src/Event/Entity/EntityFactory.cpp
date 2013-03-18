//
// EntityFactory.cpp for /home/vink/projet/cpp/Nibler-patel-ozouf/src/Event/Entity/EntityFactory.cpp in /home/vink
//
// Made by vink
// Login   <kevin platel@epitech.net>
//
// Started on  Mon Mar 18 22:29:46 2013 vink
// Last update Mon Mar 18 22:42:24 2013 vink
//

#include <iostream>
#include "EntityFactory.hh"

EntityFactory::EntityFactory()
{
}

EntityFactory::~EntityFactory()
{
  while (!this->entity.isEmpty())
    {
      delete entity.top();
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

IEntity*	EntityFactory::newEntity(std::string const &name,
					 Rect &pos, int type, Map *map, Rect *tile);
{
    std::deque<IEntity*>::iterator it;
  if ((it = std::find(this->entity.begin(), this->entity.end(), n)) != this->entity.end())
    {
      return (*it)->clone(pos, type, map, tile);
    }
  return 0;
}
