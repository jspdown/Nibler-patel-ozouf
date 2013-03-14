
#ifndef		__ACTION_EVENT_HH__
# define	__ACTION_EVENT_HH__

#include	<string>
#include	"IActionEvent.hh"
#include	"IEntity.hh"

template	<class T>
class	ActionEvent: public	IActionEvent
{
  typedef	void	(T::*Action)(const std::string&);
  Action				action;
  IEntity				*aim;

public:
  ActionEvent(void (T::*func)(const std::string&) a, IEntity *i) :
  action(a), aim(i)
  {}

  ~ActionEvent()
  {}

  ActionEvent(const ActionEvent &other):
    action(other.action), aim(other.aim)
  {}

  ActionEvent	&operator=(const ActionEvent &other)
  {
    this->action = other.getAction();
    this->aim = other.getAim();
  }

  virtual void	operator()(const std::string &trame);
  {
    (this->aim)->*action(trame);
  }

  Action	getAction()	const
  {
    return (this->action);
  }

  IEntity	getAim()	const
  {
    return (this->aim);
  }

};

#endif
