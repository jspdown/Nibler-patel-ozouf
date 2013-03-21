
#ifndef		__WALL_HH__
# define	__WALL_HH__

#include	"Rect.hh"
#include	"Map.hh"
#include	"AStaticEntity.hh"

class	Wall:	public	AStaticEntity
{
public:
  Wall(Rect *pos, int type, Map *map, Rect *r);
  virtual ~Wall();
  Wall(const Wall &other);
  Wall	&operator=(const Wall &other);

  void	collide(const std::string &trame);

  virtual void	update();
  virtual void	init();
  virtual Wall *clone(Rect *pos, int type, Map *map, Rect *r)	const;
  virtual std::map<std::string, IActionEvent *> generateEventListened();
};

#endif
