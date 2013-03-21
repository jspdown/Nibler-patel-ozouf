
#include	<algorithm>
#include	<iterator>
#include "Debug.hh"

#include	"Trame.hh"
#include	"Listener.hh"

Listener::Listener(IEntity *e):
  entity(e)
{

}

Listener::~Listener()
{

}

Listener::Listener(const Listener &other) :
  childs(other.childs), entity(other.entity), listened(other.listened)
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

bool	Listener::isListening(const std::string &name)
{
  std::map<std::string, IActionEvent *>::iterator	it = this->listened.find(name);
  Debug::write(name.c_str());
  return (it != this->listened.end());
}

void	Listener::broadcast(const std::string&trame)
{
  Listener::AppliBroadcast	a(trame);

  if (this->entity && this->isListening(Trame::getName(trame)))
    {
      (*(this->listened[Trame::getName(trame)]))(trame);
    }
  std::for_each(this->childs.begin(), this->childs.end(), a);
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
