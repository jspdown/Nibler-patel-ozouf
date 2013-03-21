
#ifndef		__SNAKEPART_HH__
# define	__SNAKEPART_HH__

#include	"AStaticEntity.hh"

class	SnakePart: public	AStaticEntity
{
public:
  SnakePart(Rect *pos, int type, Map *map, Rect *r);
  virtual ~SnakePart();

  virtual void	update();
  virtual void	init();
  virtual SnakePart *clone(Rect *pos, int type, Map *map, Rect *r)	const;
  virtual std::map<std::string, IActionEvent *> generateEventListened();
};

#endif
