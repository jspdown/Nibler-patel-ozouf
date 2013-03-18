#ifndef __ENTITYFACTORY_H__
# define __ENTITYFACTORY_H__

#include <iostream>
#include <deque>
#include <algorithm>
#include "IEntity"
#include "Rect.hh"
#include "Map.hh"

class EntityFactory
{
  std::deque<IEntity*>	entity;
public:
  EntityFactory();
  virtual ~EntityFactory();

  void		learnEntity(IEntity *n);
  void		unlearnEntity(IEntity *n);
  IEntity*	newEntity(std::string const &name,
			  Rect &pos, int type, Map *map, Rect *tile);
};

#endif /* !__ENTITYFACTORY_H__ */
