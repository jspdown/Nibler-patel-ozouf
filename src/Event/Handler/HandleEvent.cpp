
#include	<iostream>
//
#include	"TheGame.hh"
#include	"IEntity.hh"
#include	"HandleEvent.hh"

HandleEvent::HandleEvent(Map *m)
{
  Listener	*root = new Listener(0);
  std::vector<std::list<IEntity *> > elms = m->getElements();
  for (unsigned int i = 0; i < elms.size(); ++i)
    {
      if (elms[i].size() > 0)
	{
	  Listener	*child = new Listener(0);
	  for (std::list<IEntity *>::const_iterator it = elms[i].begin(); it != elms[i].end(); ++it)
	    {
	      Listener	*sub_child = new Listener(*it);
	      sub_child->setEvents((*it)->generateEventListened());
	      child->addChild(sub_child);
	    }
	  child->setEvents((*(elms[i].begin()))->generateEventListened());
	  root->addChild(child);
	}
    }
  TheGame	*g = new TheGame(m);
  Listener	*game = new Listener(g);
  game->setEvents(g->generateEventListened());
  root->addChild(game);
  root->addEvent("*", 0);
  this->listeners = root;
}

HandleEvent::~HandleEvent()
{

}


void	HandleEvent::emit(const std::string &trame)
{
  this->listeners->broadcast(trame);
}

void	HandleEvent::update(std::stack<std::string> &s)
{
  this->listeners->update();
}
