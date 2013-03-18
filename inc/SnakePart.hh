
#ifndef		__SNAKEPART_HH__
# define	__SNAKEPART_HH__

#include	"AAnimateEntity.hh"

class	SnakePart: public	AAnimateEntity
{
public:
  SnakePart(Rect &pos,
	    int type,
	    Map *map,
	    std::pair<int, int> unit_size,
	    std::pair<int, int> img_size,
	    unsigned int nbr_frame);
  virtual ~SnakePart();

  virtual void	update();
  virtual void	init();
};

#endif
