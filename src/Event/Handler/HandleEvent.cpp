
#include	"HandleEvent.hh"

HandleEvent::HandleEvent(Listener *l) :
  listeners(l)
{

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
