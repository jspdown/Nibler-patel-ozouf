
#include	"ActionEvent.hpp"
#include	"SnakePart.hh"
#include	"Trame.hh"
#include	"Snake.hh"

#include	"Debug.hh"

Snake::Snake(Rect *pos, int type, Map *map, Rect *tile):
  AStaticEntity("snake", pos, type, map, tile)
{
  this->speed = 1;
  this->direction = Snake::TOP;
}

Snake::~Snake()
{

}

void	Snake::setDirection(e_dir d)
{
  this->direction = d;
}

void	Snake::move_left(const std::string &)
{
  if (this->direction == Snake::LEFT)
    setDirection(Snake::BOTTOM);
  else if (this->direction == Snake::RIGHT)
    setDirection(Snake::TOP);
  else if (this->direction == Snake::TOP)
    setDirection(Snake::LEFT);
  else
    setDirection(Snake::RIGHT);
}

void	Snake::move_right(const std::string &)
{
  if (this->direction == Snake::LEFT)
    setDirection(Snake::TOP);
  else if (this->direction == Snake::RIGHT)
    setDirection(Snake::BOTTOM);
  else if (this->direction == Snake::TOP)
    setDirection(Snake::RIGHT);
  else
    setDirection(Snake::LEFT);
}

void	Snake::updateQueue()
{
  std::pair<int, int>	prev = this->pos->getPos();
  std::pair<int, int>	tmp;
  for (unsigned int i = 1; i < this->queue.size(); ++i)
    {
      tmp = this->queue[i]->getPos()->getPos();
      this->queue[i]->getPos()->setPos(prev);
      prev = tmp;
    }
}

void	Snake::move()
{
  int	x = this->pos->getPos().first;
  int	y = this->pos->getPos().second;

  if (this->direction == Snake::LEFT)
    this->pos->setPos(x - this->speed, y);
  else if (this->direction == Snake::RIGHT)
    this->pos->setPos(x + this->speed, y);
  else if (this->direction == Snake::TOP)
    this->pos->setPos(x, y - this->speed);
  else
    this->pos->setPos(x, y + this->speed);
  
  std::vector<std::string>	s_targets;
  std::vector<std::string>	s_args;

  s_targets.push_back(std::string("*"));
  s_args = this->pos->posStr();  
  this->map->getHandleEvent()->emit(Trame::buildTrame("collide",
						     this->unique_id,
						     s_targets,
						     s_args));  
  this->updateQueue();
}

void	Snake::update()
{
  this->move();
}

void	Snake::collide(const std::string &trame)
{
  if (Trame::getTransmitter(trame) == this->unique_id)
    return ;
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

	  this->map->getHandleEvent()->emit(Trame::buildTrame("endOfGame",
							     this->unique_id,
							     s_targets,
							     s_args));
	}
    }
}

void	Snake::addPart()
{
  SnakePart	n(this->pos, 0, this->map, new Rect());
  this->map->addEntity(5, &n);
}

void	Snake::init()
{
}

Snake	*Snake::clone(Rect *pos, int type, Map *map, Rect *r)	const
{
  return (new Snake(pos, type, map, r));
}

std::map<std::string, IActionEvent *> Snake::generateEventListened()
{
  std::map<std::string, IActionEvent *>	events;

  events["collide"] = new ActionEvent<Snake>(&Snake::collide, this);
  events["left"] = new ActionEvent<Snake>(&Snake::move_left, this);
  events["right"] = new ActionEvent<Snake>(&Snake::move_right, this);
  //  event["eat"] = ActionEvent(Snake::collide, this);
  return (events);
}
