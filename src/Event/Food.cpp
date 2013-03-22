//
// Food.cpp for /home/vink/projet/cpp/Nibler-patel-ozouf/src/Event/Food.cpp in /home/vink/projet/cpp/Nibler-patel-ozouf
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Thu Mar 21 19:20:33 2013 kevin platel
// Last update Thu Mar 21 19:21:48 2013 kevin platel
//

#include <sys/time.h>

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
  struct timeval	time;
  gettimeofday(&time,NULL);

  srand((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	Food::setRandPos()
{
  bool	done = false;
  int	x, y;

  while (!done)
    {
      bool	nice = true;
      x = rand() % this->map->getConf()->getMapSize().first;
      y = rand() % this->map->getConf()->getMapSize().second;

      Debug::write("plop", this->map->getElements().size());
      for (unsigned int i = 0; i < this->map->getElements().size(); ++i)
	{
	  for (std::list<IEntity *>::const_iterator it = this->map->getElements()[i].begin(); 
	       it != this->map->getElements()[i].end(); ++it)
	    {
	      if ((*it)->getName() == "snake" || (*it)->getName() == "wall")
		if ((*it)->getPos()->getPos().first == x && (*it)->getPos()->getPos().second == y)
		  nice = false;
	    }
	}
      if (nice == true)
	done = true;
    }
  this->pos->setPos(x, y);
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
	  {
	    std::vector<std::string>	s_targets;
	    std::vector<std::string>	s_args;
	    s_targets.push_back(std::string("snake"));
	    s_args.push_back(std::string("1"));
	    
	    this->map->getHandleEvent()->emit(Trame::buildTrame("eat",
								this->unique_id,
								s_targets,
								s_args));
	  }
	  {
	    std::vector<std::string>	s_targets;
	    std::vector<std::string>	s_args;
	    s_targets.push_back(std::string("thegame"));
	    s_args.push_back(std::string("1"));
	    
	    this->map->getHandleEvent()->emit(Trame::buildTrame("earnspoints",
								this->unique_id,
								s_targets,
								s_args));
	  }
	  
	  this->setRandPos();
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
