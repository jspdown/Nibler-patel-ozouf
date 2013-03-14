
#include	"Listener.hh"

Listener::Listener()
{

}

Listener::~Listener()
{

}

Listener::Listener(const Listener &other) :
  childs(other.childs), entity(other.entity), listen(other.listen)
{

}

Listener	Listener::operator=(const Listener &other)
{
  this->childs = other.getChild();
  this->entity = other.getEntity();
  this->listen = other.getListened();
}

void	Listener::addEvent(const std::string &name, IActionEvent *a)
{
  this->listened[name] = a;
}

void	Listener::removeEvent(const std::string &name)
{
  std::map<std::string, IActionEvent *>::const_iterator	it = this->listened.find(name);
  if (it != this->listened.end())
    this->listened.erase(it);
}

void	Listener::addChild(Listener *l)
{
  if (std::find(this->listened.begin(), this->listened.end(), l) == this->listened.end())
    this->childs.push_back(l);
}

void	Listener::removeChild(Listener *l)
{
  std::deque<Listener *>::const_iterator	it = std::find(this->listened.begin(), this->listened.end(), l);
  if (it != this->listened.end())
    his->listened.erase(it);
}

bool	Listener::isListening(const std::string &name)
{
  std::map<std::string, IActionEvent *>::const_iterator	it = this->listened.find(name);
  return (it != this->listened.end());
}

void	Listener::broadcast(const std::string&trame)
{
  Listener::AppliBroadcast	a(trame);
  
  if (this->entity)
    *(this->listened[Trame::getName(trame)])(trame);
  for_each(this->childs.begin(), this->childs.end(), a);
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



AppliBroadcast::AppliBroadcast(std::deque<std::string, IActionEvent *> &childs) :
  childs(childs)
{  
  
}

AppliBroadcast::~AppliBroadcast()
{

}

void	AppliBroadcast::operator()(const Listener *child)
{
  if (child != 0)
    if (child.isListening(Trame::getName(this->trame)))
      child.broadcast(this->trame);
}
