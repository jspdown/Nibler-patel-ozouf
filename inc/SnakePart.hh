
#ifndef		__SNAKEPART_HH__
# define	__SNAKEPART_HH__

#include	"AStaticEntity.hh"
#include	"Snake.hh"

class	Snake;

class	SnakePart: public	AStaticEntity
{
  e_dir	direction;
public:
  SnakePart(Rect *pos, int type, Map *map, Rect *r);
  virtual ~SnakePart();

  virtual void	update();
  virtual void	init();
  void	setDir(e_dir dir);
  e_dir	getDir()	const;
  void	checkCorner(Rect *before, Rect *after);
  virtual SnakePart *clone(Rect *pos, int type, Map *map, Rect *r)	const;
  virtual std::map<std::string, IActionEvent *> generateEventListened();

  void	collide(const std::string &trame);
private:
  bool	getCorner(int, int, int, int, int, int, int, int);
};

#endif
