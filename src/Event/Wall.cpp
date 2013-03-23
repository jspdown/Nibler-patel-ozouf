
#include	"ActionEvent.hpp"
#include	"Trame.hh"
#include	"Wall.hh"

#include	"Debug.hh"

Wall::Wall(Rect *pos, int type, Map *map, Rect *tile) :
  AStaticEntity("wall", pos, type, map, tile)
{
}

Wall::~Wall()
{

}

Wall::Wall(const Wall &other):
  AStaticEntity(other)
{

}

void	Wall::collide(const std::string &trame)
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
	  s_targets.push_back(std::string("theGame"));
	  s_args.push_back(std::string("collide with a wall"));

	  this->map->getHandleEvent()->emit(Trame::buildTrame(/*"endOfGame"*/ "quit",
							     this->unique_id,
							     s_targets,
							     s_args));
	}
    }
}

void	Wall::update()
{

}

void	Wall::init()
{

}

Wall *Wall::clone(Rect *pos, int type, Map *map, Rect *r)	const
{
  return (new Wall(pos, type, map, r));
}

std::map<std::string, IActionEvent *> Wall::generateEventListened()
{
  std::map<std::string, IActionEvent *>	events;

  events["collide"] = new ActionEvent<Wall>(&Wall::collide, this);
  return (events);
}
