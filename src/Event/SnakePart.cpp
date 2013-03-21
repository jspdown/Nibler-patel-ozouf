
#include	"ActionEvent.hpp"
#include	"Trame.hh"
#include	"SnakePart.hh"

#include	"Debug.hh"

SnakePart::SnakePart(Rect *pos, int type, Map *map, Rect *r):
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
