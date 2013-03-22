
#include	<algorithm>
#include	<iterator>
#include "Debug.hh"

#include	"Trame.hh"
#include	"Listener.hh"

Listener::Listener(IEntity *e, const std::string &name):
  entity(e)
{
  this->name = name;
}

Listener::~Listener()
{

}

Listener::Listener(const Listener &other) :
  childs(other.childs), entity(other.entity), listened(other.listened), name(name)
{
  
}

Listener	Listener::operator=(const Listener &other)
{
  this->childs = other.getChild();
  this->entity = other.getEntity();
  this->listened = other.getListened();
  return (*this);
}

void	Listener::setEvents(const std::map<std::string, IActionEvent *> &e)
{
  this->listened = e;
}

void	Listener::addEvent(const std::string &name, IActionEvent *a)
{
  this->listened[name] = a;
}

void	Listener::removeEvent(const std::string &name)
{
  std::map<std::string, IActionEvent *>::iterator	it = this->listened.find(name);
  if (it != this->listened.end())
    this->listened.erase(it);
}

void	Listener::addChild(Listener *l)
{
  if (std::find(this->childs.begin(), this->childs.end(), l) == this->childs.end())
    this->childs.push_back(l);
}

void	Listener::removeChild(Listener *l)
{
  std::deque<Listener *>::iterator it = std::find(this->childs.begin(), this->childs.end(), l);
  if (it != this->childs.end())
    this->childs.erase(it);

}
void	Listener::removeChild(Listener *father, IEntity *l)
{
  if (this->entity == l)
    father->removeChild(this);
  else
    for (unsigned int i = 0; i < this->childs.size(); ++i)
      this->childs[i]->removeChild(this, l);
}
bool	Listener::isListening(const std::string &name)
{
  for (std::map<std::string, IActionEvent *>::const_iterator it = this->listened.begin(); it != this->listened.end(); ++it)
    {
      if ((*it).first == name)
	return (true);
    }
  return (false);
}

void	Listener::broadcast(const std::string&trame)
{
  Listener::AppliBroadcast	a(trame);

  if (this->entity && this->isListening(Trame::getName(trame)))
    (*(this->listened[Trame::getName(trame)]))(trame);

  for (unsigned int i = 0; i < this->childs.size(); ++i)
    {
      if (this->childs[i]->isListening(Trame::getName(trame)))
	{
	  this->childs[i]->broadcast(trame);
	}
    }
}

void	Listener::update()
{
  if (this->entity)
    this->entity->update();
}

std::deque<Listener *>		Listener::getChild()	const
{
  return (this->childs);
}

IEntity				*Listener::getEntity()	const
{
  return (this->entity);
}

std::map<std::string, IActionEvent *>	Listener::getListened()	const
{
  return (this->listened);
}



Listener::AppliBroadcast::AppliBroadcast(const std::string &trame) :
  trame(trame)
{

}

Listener::AppliBroadcast::~AppliBroadcast()
{

}

void	Listener::AppliBroadcast::operator()(Listener *child)
{
  if (child != 0)
    {
      if (child->isListening(Trame::getName(this->trame)))
	{
	  child->broadcast(this->trame);
	}
    }
}

std::string	Listener::getName()	const
{
  return (this->name);
}

void		Listener::init()
{
  if (this->entity)
    this->entity->init();
  for (unsigned int i = 0; i < this->childs.size(); ++i)
    this->childs[i]->init();
}
