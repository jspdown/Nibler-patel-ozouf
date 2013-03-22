#include <algorithm>
#include	"AAnimateEntity.hh"

AAnimateEntity::AAnimateEntity(const std::string &name,
			       Rect *pos,
			       int type,
			       Map *map,
			       std::pair<int, int> unit_size,
			       std::pair<int, int> img_size,
			       unsigned int nbr_frame) :
  AEntity(name, pos, type, map)
{
  int	nbr_l = img_size.first / unit_size.first;
  int	nbr_h = img_size.second / unit_size.second;

  for (unsigned int i = 0; i < nbr_frame; ++i)
    {
      int	x = (i % nbr_l) * unit_size.first;
      int	y = (i / nbr_h) * unit_size.second;

      this->frame.push_back(new Rect(x, y, unit_size.first, unit_size.second));
    }
  this->is_running = false;
  this->offset = 0;
  this->unit_size = unit_size;
}

AAnimateEntity::~AAnimateEntity()
{
  AAnimateEntity::DeleteFrame	del;
  std::for_each(this->frame.begin(), this->frame.end(), del);
  this->frame.clear();
}

void		AAnimateEntity::nextFrame()
{
  if (this->offset < this->frame.size())
    ++(this->offset);
  this->offset = 0;
}

Rect	const *AAnimateEntity::getRect()	const
{
  return (this->frame[this->offset]);
}

void	AAnimateEntity::DeleteFrame::operator()(Rect *r)
{
  delete r;
}
