
#ifndef		__LISTENER_H__
# define	__LISTENER_H__

#include	<deque>
#include	<map>
#include	<string>
#include	"IActionEvent.hh"
#include	"IEntity.hh"

class	Listener
{
  std::deque<Listener *>		childs;
  IEntity				*entity;
  std::map<std::string, IActionEvent *>	listened;
public:
  Listener(IEntity *e);
  ~Listener();
  Listener(const Listener &other);
  Listener	operator=(const Listener &other);

  void	addEvent(const std::string &name, IActionEvent *a);
  void	removeEvent(const std::string &name);
  void	addChild(Listener *l);
  void	removeChild(Listener *l);
  void	broadcast(const std::string &trame);

  void	update();
  bool	isListening(const std::string &name);

  std::deque<Listener *>		getChild()	const;
  IEntity				*getEntity()	const;
  std::map<std::string, IActionEvent *>	getListened()	const;

  void	state()	const;
  class	AppliBroadcast
  {
    std::string	trame;
  public:
    AppliBroadcast(const std::string &trame);
    ~AppliBroadcast();

    void	operator()(Listener *child);
  };
};


#endif
