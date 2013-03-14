
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
  IEntity				aim;

public:
  ActionEvent(Action a, IEntity &i);
  virtual ~ActionEvent();
  ActionEvent(const ActionEvent &other);
  ActionEvent	&operator=(const ActionEvent &other);

  virtual void	operator()(const std::string &trame);
  
  Action	getAction()	const;
  IEntity	getAim()	const;
};

#endif
