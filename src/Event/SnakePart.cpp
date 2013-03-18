
#include	"SnakePart.hh"

SnakePart::SnakePart(Rect &pos,
		     int type,
		     Map *map,
		     std::pair<int, int> unit_size,
		     std::pair<int, int> img_size,
		     unsigned int nbr_frame) :
  AAnimateEntity(std::string("snakePart"),
		 pos,
		 type,
		 map,
		 unit_size,
		 img_size,
		 nbr_frame)
{

}

SnakePart::~SnakePart()
{

}

void	SnakePart::update()
{

}

void	SnakePart::init()
{

}
