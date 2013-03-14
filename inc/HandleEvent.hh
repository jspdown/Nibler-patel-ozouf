
#ifndef		__HANDLEEVENT_HH__
# define	__HANDLEEVENT_HH__

#include	<string>
#include	<stack>
#include	"Listerner.hh"

class	HandleEvent
{
  Listener	*listeners;
public:
  HandleEvent(Listener *l);
  ~HandleEvent();
  HandleEvent(const HandleEvent &other);
  HandleEvent	operator=(const HandleEvent &other);

  void	emit(const std::string &trame);
  void	update(std::stack<std::string> &s);
};

#endif
