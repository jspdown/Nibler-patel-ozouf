
#ifndef		__IENTITY_HH__
# define	__IENTITY_HH__

#include	"Rect.hh"

class	IEntity
{
public:
  virtual ~IEntity(){}

  virtual void	init() = 0;
  virtual void	update() = 0;
  virtual void	state() const = 0; // debug methode
  virtual Rect	*getRect() const = 0;
};

#endif
