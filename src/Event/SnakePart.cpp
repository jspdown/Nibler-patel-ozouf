
#include	"ActionEvent.hpp"
#include	"Trame.hh"
#include	"SnakePart.hh"

#include	"Debug.hh"

SnakePart::SnakePart(Rect *pos, int type, Map *map, Rect *r):
  AStaticEntity("snakepart", pos, type, map, r)
{
  this->direction = TOP;
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

void	SnakePart::collide(const std::string &trame)
{
  std::vector<std::string> args = Trame::getArgs(trame);

  if (args.size() == 4)
    {
      if (this->pos->is_inside(Rect(Trame::toInt(args[0]),
				    Trame::toInt(args[1]),
				    Trame::toInt(args[2]),
				    Trame::toInt(args[3]))))
	{
	  std::vector<std::string>	s_targets;
	  std::vector<std::string>	s_args;
	  s_targets.push_back(std::string("thegame"));
	  s_args.push_back(std::string("collide with a wall"));

	  this->map->getHandleEvent()->emit(Trame::buildTrame("quit"/*endOfGame"*/,
							     this->unique_id,
							     s_targets,
							     s_args));
	}
    }
}


SnakePart *SnakePart::clone(Rect *pos, int type, Map *map, Rect *r)	const
{
  return (new SnakePart(pos, type, map, r));
}

std::map<std::string, IActionEvent *> SnakePart::generateEventListened()
{
  std::map<std::string, IActionEvent *>	events;
  events["collide"] = new ActionEvent<SnakePart>(&SnakePart::collide, this);
  return (events);
}

void	SnakePart::setDir(e_dir dir)
{
  this->direction = dir;
  if (dir == LEFT)
    this->rect.setTexture("snakepart-left");
  else if (dir == RIGHT)
    this->rect.setTexture("snakepart-right");
  else if (dir == TOP)
    this->rect.setTexture("snakepart-top");
  else
    this->rect.setTexture("snakepart-bottom");
}

bool	SnakePart::getCorner(int x1, int x2, int y1, int y2, int x1_test, int y1_test, int x2_test, int y2_test)
{
  if ((x1 == this->pos->getPos().first + x1_test && y1 == this->pos->getPos().second + y1_test &&
       x2 == this->pos->getPos().first + x2_test && y2 == this->pos->getPos().second + y2_test) ||
      (x1 == this->pos->getPos().first + x2_test && y1 == this->pos->getPos().second + y2_test &&
       x2 == this->pos->getPos().first + x1_test && y2 == this->pos->getPos().second + y1_test))
    return (true);
  return (false);
}

void	SnakePart::checkCorner(Rect *before, Rect *after)
{
  int	x1 = before->getPos().first;
  int	y1 = before->getPos().second;

  int	x2 = after->getPos().first;
  int	y2 = after->getPos().second;

  if (getCorner(x1, x2, y1, y2, 0, -1, -1, 0))
    this->pos->setTexture("snakepart-corner1");
  else if (getCorner(x1, x2, y1, y2, -1, 0, 0, 1))
    this->pos->setTexture("snakepart-corner2");
  else if (getCorner(x1, x2, y1, y2, 1, 0, 0, 1))
    this->pos->setTexture("snakepart-corner3");
  else if (getCorner(x1, x2, y1, y2, 0, -1, 1, 0))
    this->pos->setTexture("snakepart-corner4");
}

e_dir	SnakePart::getDir()	const
{
  return (this->direction);
}
