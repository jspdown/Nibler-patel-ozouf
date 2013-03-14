
#ifndef		__AANIMATEENTITY_HH__
# define	__AANIMATEENTITY_HH__

#include	"AEntity.hh"

class	AAnimateEntity: public	AEntity
{
  std::vector<Rect *>	frame;
  bool			is_running;
  int			offset;
  std::pair<int, int>	unit_size;
public:
  AAnimateEntity(const std::string &name,
		 std::pair<int, int> &pos,
		 int type,
		 Map *map, 
		 std::pair<int, int> unit_size,
		 std::pair<int, int> img_size,
		 int nbr_frame);
  virtual ~AAnimateEntity();

  virtual Rect	*getRect()	const;
  void		nextFrame();

  class	DeleteFrame
  {
    void	operator()(Rect *r);
  };
};

#endif
