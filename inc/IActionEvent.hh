
#ifndef		__IACTION_EVENT_HH__
# define	__IACTION_EVENT_HH__

#include	<string>

class	IActionEvent
{
public:
  virtual void	operator()(const std::string &trame) = 0;
};

#endif
