
#include	<iostream>
//
#include	"TheGame.hh"
#include	"IEntity.hh"
#include	"HandleEvent.hh"
#include	"Listener.hh"
#include	<string>
#include	<map>
#include	<vector>
#include	"Debug.hh"



HandleEvent::HandleEvent(Map *m)
{
  Listener	*root = new Listener(0, std::string("root"));
  std::vector<std::list<IEntity *> > elms = m->getElements(); 
  std::map<std::string, Listener *> listen = this->generateListeners(elms);
  
  for (std::map<std::string, Listener *>::const_iterator it = listen.begin(); it != listen.end(); ++it)
    root->addChild((*it).second);
  
  TheGame	*g = new TheGame(m);
  Listener	*game = new Listener(g, std::string("the game"));
  
  game->setEvents(g->generateEventListened());
  root->addChild(game);
  root->addEvent("*", 0);
  this->listeners = root;
}

std::map<std::string, Listener *>	HandleEvent::generateListeners(std::vector<std::list<IEntity *> > &elms)
{
  std::map<std::string, Listener *>	ent;
  std::string				name;
  bool					found;

  for (unsigned int i = 0; i < elms.size(); ++i)
    {
      for (std::list<IEntity *>::const_iterator it = elms[i].begin(); it != elms[i].end(); ++it)
	{
	  found = false;
	  name = (*it)->getName();
	  for (std::map<std::string, Listener *>::const_iterator itm = ent.begin(); itm != ent.end(); ++itm)
	    if ((*itm).first == name)
	      {
		found = true;
		Listener *nls = new Listener(*it, name);
		nls->setEvents((*it)->generateEventListened());
		(*itm).second->addChild(nls);
	      }
	  if (!found)
	    {
	      ent[name] = new Listener(0, name);
	      Listener *nl = new Listener(*it, name);
	      nl->setEvents((*it)->generateEventListened());
	      ent[name]->addChild(nl);
	      ent[name]->setEvents((*it)->generateEventListened());
	    }
	}
    }
  return (ent);
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

void	HandleEvent::init()
{
  this->listeners->init();
}

Listener	*HandleEvent::getListeners()	const
{
  return (this->listeners);
}
