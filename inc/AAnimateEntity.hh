
#ifndef		__AANIMATEENTITY_HH__
# define	__AANIMATEENTITY_HH__

#include	"Rect.hh"
#include	"AEntity.hh"

class	AAnimateEntity: public	AEntity
{
  std::vector<Rect *>	frame;
  bool			is_running;
  unsigned int		offset;
  std::pair<int, int>	unit_size;
public:
  AAnimateEntity(const std::string &name,
		 Rect	*pos,
		 int type,
		 Map *map,
		 std::pair<int, int> unit_size,
		 std::pair<int, int> img_size,
		 unsigned int nbr_frame);
  virtual ~AAnimateEntity();

  virtual Rect	const *getRect()	const;
  void		nextFrame();

  class	DeleteFrame
  {
  public:
    void	operator()(Rect *r);
  };
};

#endif
