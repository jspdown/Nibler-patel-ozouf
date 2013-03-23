
#ifndef		__IENTITY_HH__
# define	__IENTITY_HH__

#include	<map>
#include	<string>
#include	"IActionEvent.hh"
#include	"Rect.hh"

class Map;

class	IEntity
{
public:
  virtual ~IEntity(){}

  virtual void	init() = 0;
  virtual void	update() = 0;
  virtual void	state() const = 0; // debug methode
  virtual Rect	const *getRect() const = 0;
  virtual Rect const	*getPos() const = 0;
  virtual const std::string	&getName() const = 0;
  virtual IEntity *clone(Rect *pos, int type, Map *map, Rect *r) const = 0;
  virtual std::map<std::string, IActionEvent *>	generateEventListened() = 0;
};

#endif
