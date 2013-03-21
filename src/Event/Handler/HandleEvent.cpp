
#include	<iostream>
//
#include	"TheGame.hh"
#include	"IEntity.hh"
#include	"HandleEvent.hh"

#include	"Debug.hh"

HandleEvent::HandleEvent(Map *m)
{
  Listener	*root = new Listener(0, std::string("root"));
  std::vector<std::list<IEntity *> > elms = m->getElements();
  for (unsigned int i = 0; i < elms.size(); ++i)
    {
      Debug::write("nbr ", i);
      if (elms[i].size() > 0)
	{
	  std::string	name((*(elms[i].begin()))->getPos()->getTexture());
	  Debug::write(name.c_str());
	  Listener	*child = new Listener(0, std::string("R") + name);
	  for (std::list<IEntity *>::const_iterator it = elms[i].begin(); it != elms[i].end(); ++it)
	    {
	      Listener	*sub_child = new Listener(*it, std::string((*(elms[i].begin()))->getPos()->getTexture()));
	      sub_child->setEvents((*it)->generateEventListened());
	      child->addChild(sub_child);
	    }
	  child->setEvents((*(elms[i].begin()))->generateEventListened());
	  root->addChild(child);
	}
    }
  TheGame	*g = new TheGame(m);
  Listener	*game = new Listener(g, std::string("the game"));
  game->setEvents(g->generateEventListened());
  root->addChild(game);
  root->addEvent("*", 0);
  this->listeners = root;
  Debug::write("###############################################");
}

HandleEvent::~HandleEvent()
{

}


void	HandleEvent::emit(const std::string &trame)
{
  Debug::write("BEGIN");
  this->listeners->broadcast(trame);
  Debug::write("END");
}

void	HandleEvent::update(std::stack<std::string> &s)
{
  this->listeners->update();
}
