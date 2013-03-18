
#ifndef		__SNAKE_HH__
# define	__SNAKE_HH__

#include	<utility>
#include	<vector>
#include	"AAnimateEntity.hh"
#include	"SnakePart.hh"	

class	Snake: public	AAnimateEntity
{
  enum	e_dir
    {
      LEFT,
      RIGHT,
      TOP,
      BOTTOM
    };
  e_dir	direction;
  std::vector<SnakePart *>	queue;
  int				speed;
public:
  Snake(Rect &pos,
	int type,
	Map *map,
	std::pair<int, int> unit_size,
	std::pair<int, int> img_size,
	unsigned int nbr_frame, 
	int	speed);
  virtual ~Snake();
  
  void	move(const std::string &trame);
  void	move_left(const std::string &trame);
  void	move_right(const std::string &trame);
  void	setDirection(e_dir d);
  void	updateQueue();
  void	addPart();
  void	collide(const std::string &trame);

  virtual void	update();
  virtual void	init();
};

#endif
