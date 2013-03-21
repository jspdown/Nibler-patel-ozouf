
#ifndef		__HANDLEEVENT_HH__
# define	__HANDLEEVENT_HH__

#include	<vector>
#include	<list>
#include	<string>
#include	<stack>
#include	"Listener.hh"

class	HandleEvent
{
  Listener	*listeners;
public:
  HandleEvent(Map *m);
  ~HandleEvent();
  HandleEvent(const HandleEvent &other);
  HandleEvent	&operator=(const HandleEvent &other);

  void	emit(const std::string &trame);
  void	update(std::stack<std::string> &s);
  void	init();
};

#endif
