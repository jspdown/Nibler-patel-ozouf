#ifndef __MAP_H__
# define __MAP_H__

#include <iostream>
#include <deque>
#include <stack>
#include <vector>
#include <list>
#include "Rect.hh"
#include "Config.hh"

class Map
{
private:
  std::map<int, std::deque<Rect*> >	aux_display;
  Config*				conf;
  HandleEvent*				event;
  std::stack<std::string>		event_stack;
  std::vector< std::list<IEntity*> >	elements;
public:
  Map(HandleEvent* event, Config *conf, std::string const &filename);
  virtual ~Map();

  void					open(std::string const &filename);

  void					pushEvent(std::string const &event);
  std::string				popEvent();
  bool					eventIsEmpty() const;

  void					addEntity(unsigned int layer, IEntity* item);
  void					delEntity(unsigned int layer, IEntity* item);
  void					delEntity(IEntity* item);
  std::vector< std::list<IEntity*> > &	getElements() const;

  std::deque<Rect*>			getAuxDisplay(int uid) const;
  void					setAuxDisplay(int uid, std::deque<Rect*>&aux_display);
};

#endif /* !__MAP_H__ */
