
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
  T				*aim;

public:
  ActionEvent(Action a, T *i) :
    action(a), aim(i)
  {}

  ~ActionEvent()
  {}

  ActionEvent(const ActionEvent<T> &other):
    action(other.action), aim(other.aim)
  {}

  ActionEvent	&operator=(const ActionEvent<T> &other)
  {
    this->action = other.getAction();
    this->aim = other.getAim();
  }

  virtual void	operator()(const std::string &trame)
  {
    ((this->aim)->*(this->action))(trame);
  }

  Action	getAction()	const
  {
    return (this->action);
  }

  T	*getAim()	const
  {
    return (this->aim);
  }

};

#endif
