//
// Map.cpp for /home/vink/projet/cpp/Nibbler/src/Map.cpp in /home/vink
//
// Made by vink
// Login   <kevin platel@epitech.net>
//
// Started on  Wed Mar 13 09:54:24 2013 vink
//

#include <iostream>
#include "Map.hh"

Map::Map(HandleEvent* event, Config *conf, std::string const &filename)
{
  this->conf = conf;
  this->event = event;
  this->filename = filename;
}

Map::~Map()
{
}

void					Map::pushEvent(std::string const &event)
{
  this->event_stack.push(event);
}

std::string				Map::popEvent()
{
  std::string	tmp;

  if (this->event_stack.empty())
    return ("");
  tmp = this->event_stack.top();
  this->event_stack.pop();
  return (tmp);
}

void					Map::addEntity(unsigned int line, IEntity* item)
{
  while (line < this->elements.size())
    {
      std::list<IEntity*> tmp;

      this->elements.push_back(tmp);
    }
  this->elements[line].push_bask(item);
}

void					Map::delEntity(unsigned int layer, IEntity* item)
{
  if (layer >= this->elements.size())
    return ;
  this->elements[layer].erase(find(this->elements[layer], item));
}

void					Map::delEntity(IEntity* item)
{
  if (layer >= this->elements.size())
    return ;
  for (unsigned int i = 0; i < this->elements.size() ; i++)
    this->elements[i].erase(find(this->elements[layer], item));
}

bool					Map::eventIsEmpty() const
{
  return this->event_stack.empty()
}

std::vector< std::list<IEntity*> > &	Map::getElements() const
{
  return (this->elements);
}

std::deque<Rect*>			Map::getAuxDisplay(int uid) const
{
  return (this->aux_display[uid]);
}

void					Map::setAuxDisplay(int uid, std::deque<Rect*>&aux_display)
{
  this->aux_display[uid] = aux_display;
}
