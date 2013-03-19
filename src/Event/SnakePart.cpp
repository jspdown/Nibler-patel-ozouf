
#include	"SnakePart.hh"

SnakePart::SnakePart(Rect &pos, int type, Map *map, Rect *r):
  AStaticEntity("snakepart", pos, type, map, r)
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

SnakePart *SnakePart::clone(Rect &pos, int type, Map *map, Rect *r)	const
{
  return (new SnakePart(pos, type, map, r));
}
