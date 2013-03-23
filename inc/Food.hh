#ifndef __FOOD_H__
# define __FOOD_H__


#include	"Rect.hh"
#include	"Map.hh"
#include	"AStaticEntity.hh"

class	Food:	public	AStaticEntity
{
public:
  Food(Rect *pos, int type, Map *map, Rect *r);
  virtual ~Food();
  Food(const Food &other);
  Food	&operator=(const Food &other);

  virtual void	update();
  virtual void	init();
  virtual Food *clone(Rect *pos, int type, Map *map, Rect *r)	const;
  virtual std::map<std::string, IActionEvent *> generateEventListened();

  void	collide(const std::string &trame);
  void	setRandPos();
};


#endif /* !__FOOD_H__ */
