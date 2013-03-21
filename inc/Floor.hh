#ifndef __FLOOR_H__
# define __FLOOR_H__

#include	"Rect.hh"
#include	"Map.hh"
#include	"AStaticEntity.hh"

class	Floor:	public	AStaticEntity
{
public:
  Floor(Rect *pos, int type, Map *map, Rect *r);
  virtual ~Floor();
  Floor(const Floor &other);
  Floor	&operator=(const Floor &other);

  virtual void	update();
  virtual void	init();
  virtual Floor *clone(Rect *pos, int type, Map *map, Rect *r)	const;
  virtual std::map<std::string, IActionEvent *> generateEventListened();
};

#endif /* !__FLOOR_H__ */
