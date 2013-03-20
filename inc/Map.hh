#ifndef __MAP_H__
# define __MAP_H__

#include <iostream>
#include <deque>
#include <stack>
#include <vector>
#include <list>
#include <map>
#include "HandleEvent.hh"
#include "Rect.hh"
#include "Config.hh"
#include "EntityFactory.hh"

class	IEntity;

class Map
{
private:
  HandleEvent*				event;
  Config*				conf;
  std::string				filename;
  std::map<int, std::deque<Rect*> >	aux_display;
  std::stack<std::string>		event_stack;
  std::vector< std::list<IEntity*> >	elements;
  EntityFactory				fact;

  IEntity*				getEntity(std::string const &line);
public:
  Map(Config *conf, std::string const &filename);
  virtual ~Map();

  void					open(std::string const &filename);

  void					pushEvent(std::string const &event);
  std::string				popEvent();
  bool					eventIsEmpty() const;

  void					addEntity(unsigned int layer, IEntity* item);
  void					delEntity(unsigned int layer, IEntity* item);
  void					delEntity(IEntity* item);
  std::vector< std::list<IEntity*> > const &	getElements() const;

  std::deque<Rect*> const &			getAuxDisplay(int uid);
  void					setAuxDisplay(int uid, std::deque<Rect*>&aux_display);
  HandleEvent*				getHandleEvent() const;
  void					setHandleEvent(HandleEvent *e);
};

#endif /* !__MAP_H__ */
