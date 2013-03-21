//
// Food.cpp for /home/vink/projet/cpp/Nibler-patel-ozouf/src/Event/Food.cpp in /home/vink/projet/cpp/Nibler-patel-ozouf
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Thu Mar 21 19:20:33 2013 kevin platel
// Last update Thu Mar 21 19:21:48 2013 kevin platel
//

#include	"ActionEvent.hpp"
#include	"Trame.hh"
#include	"Food.hh"

#include	"Debug.hh"

Food::Food(Rect *pos, int type, Map *map, Rect *tile) :
  AStaticEntity("food", pos, type, map, tile)
{
}

Food::~Food()
{

}

Food::Food(const Food &other):
  AStaticEntity(other)
{

}

void	Food::update()
{

}

void	Food::init()
{

}

void	Food::collide(const std::string &trame)
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
	  s_targets.push_back(std::string("snake"));
	  s_args.push_back(std::string("1"));
	  
	  this->map->getHandleEvent()->emit(Trame::buildTrame("eat",
							     this->unique_id,
							     s_targets,
							     s_args));
	  Debug::write("PPPPP");
	  this->map->getHandleEvent()->getListeners()->removeChild(map->getHandleEvent()->getListeners(), this);
	  Debug::write("AAA");
	  this->map->delEntity(this);
	  Debug::write("BBB");
	}
    }
}


Food *Food::clone(Rect *pos, int type, Map *map, Rect *r)	const
{
  return (new Food(pos, type, map, r));
}

std::map<std::string, IActionEvent *> Food::generateEventListened()
{
  std::map<std::string, IActionEvent *>	events;
  events["collide"] = new ActionEvent<Food>(&Food::collide, this);
  return (events);
}
