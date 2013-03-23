//
// Map.cpp for /home/vink/projet/cpp/Nibbler/src/Map.cpp in /home/vink
//
// Made by vink
// Login   <kevin platel@epitech.net>
//
// Started on  Wed Mar 13 09:54:24 2013 vink
//

#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Map.hh"

Map::Map(Config *conf, std::string const &filename)
{
  std::fstream file(filename.c_str());
  std::string	str;
  std::stringstream ss;
  IEntity *tmp;

  this->conf = conf;
  this->event = event;
  this->filename = filename;
  std::getline(file, str, '\n');
  ss << str;
  ss >> this->size.first;
  ss >> this->size.second;
  for (int i = 0; i < this->size.second; ++i)
    {
      for (int j = 0; j < this->size.first; ++j)
	{
	  tmp = this->fact.newEntity("floor",
				     new Rect(i,
					      j),
					      0,
					      this,
					      new Rect(conf->getTileSize().first,
						       conf->getTileSize().second,
						       32,
						       32));
	  if (tmp)
	    this->addEntity(0, tmp);
	}
    }
  while (std::getline(file, str, '\n'))
    {
      this->getEntity(str);
    }
  this->event = new HandleEvent(this);
}

Map::~Map()
{
}

std::pair<int, int> const &		Map::getSize() const
{
  return (this->size);
}

IEntity				       *Map::getEntity(std::string const &line)
{
  std::stringstream ss;
  std::string name;
  int	x;
  int	y;
  int	width;
  int	height;
  int	layer;
  IEntity *tmp;

  ss << line;
  std::getline(ss, name, ' ');
  ss >> layer;
  ss >> x;
  ss >> y;
  ss >> width;
  ss >> height;
  tmp = this->fact.newEntity(name, new Rect(x, y), 0, this,
			     new Rect(conf->getTileSize().first, conf->getTileSize().second, 32, 32, "bite", "wall"));
  if (!tmp)
    return (0);
  this->addEntity(layer, tmp);
  return (tmp);
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

std::stack<std::string>	&		Map::getEvent()
{
  return (this->event_stack);
}

void					Map::addEntity(unsigned int line, IEntity* item)
{
  while (line >= this->elements.size())
    {
      std::list<IEntity*> tmp;

      this->elements.push_back(tmp);
    }
  this->elements[line].push_back(item);
}

void					Map::delEntity(unsigned int layer, IEntity* item)
{
  if (layer >= this->elements.size())
    return ;
  (this->elements[layer]).erase(std::find(this->elements[layer].begin(), this->elements[layer].end(), item));
}

void					Map::delEntity(IEntity* item)
{
  for (unsigned int i = 0; i < this->elements.size() ; i++)
    {
      if (std::find(this->elements[i].begin(), this->elements[i].end(), item) != this->elements[i].end())
	this->elements[i].erase(std::find(this->elements[i].begin(), this->elements[i].end(), item));
    }
}

bool					Map::eventIsEmpty() const
{
  return this->event_stack.empty();
}

std::vector< std::list<IEntity*> > const &	Map::getElements() const
{
  return (this->elements);
}

std::deque<Rect*> const &			Map::getAuxDisplay(int uid)
{
  return ((this->aux_display[uid]));
}

void					Map::setAuxDisplay(int uid, std::deque<Rect*>&aux_display)
{
  this->aux_display[uid] = aux_display;
}

HandleEvent*				Map::getHandleEvent() const
{
  return (this->event);
}

void					Map::setHandleEvent(HandleEvent *e)
{
  this->event = e;
}

void					Map::updateEvent()
{
  while (!this->event_stack.empty())
    this->event->emit(this->popEvent());
}

void					Map::setEngine(Engine *e)
{
  this->engine = e;
}
Engine					*Map::getEngine()	const
{
  return (this->engine);
}

Config					*Map::getConf()
{
  return (this->conf);
}
