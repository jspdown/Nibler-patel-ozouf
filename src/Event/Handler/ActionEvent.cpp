
#include	"IActionEvent.hh"
#include	"ActionEvent.hh"

ActionEvent::ActionEvent(void (T::*func)(const std::string&) a, IEntity &i) :
  action(a), aim(i)
{

}

ActionEvent::~ActionEvent()
{

}

ActionEvent::ActionEvent(const ActionEvent &other):
  action(other.action), aim(other.aim)
{

}

ActionEvent	&ActionEvent::operator=(const ActionEvent &other)
{
  this->action = other.getAction();
  this->aim = other.getAim();
}

virtual void	ActionEvent::operator()(const std::string &trame);
{
  this->aim.*action(trame);
}

Action	ActionEvent::getAction()	const
{
  return (this->action);
}

IEntity	ActionEvent::getAim()	const
{
  return (this->aim);
}
