
#ifndef		__SNAKE_HH__
# define	__SNAKE_HH__

#include	<utility>
#include	<vector>
#include	"AStaticEntity.hh"
#include	"SnakePart.hh"	

class SnakePart;

enum	e_dir
  {
    LEFT,
    RIGHT,
    TOP,
    BOTTOM
  };

class	Snake: public	AStaticEntity
{
  e_dir	direction;
  std::vector<SnakePart *>	queue;
  int				speed;
public:
  Snake(Rect *pos, int type, Map *map, Rect *r);
  virtual ~Snake();
  
  void	move();
  void	setDirection(e_dir d);
  e_dir	getDir()	const;
  void	updateQueue();
  void	addPart();

  void	eat(const std::string &trame);
  void	collide(const std::string &trame);
  void	move_left(const std::string &trame);
  void	move_right(const std::string &trame);
  
  virtual void	update();
  virtual void	init();
  virtual Snake *clone(Rect *pos, int type, Map *map, Rect *r)	const;

  virtual std::map<std::string, IActionEvent *> generateEventListened();
};

#endif
