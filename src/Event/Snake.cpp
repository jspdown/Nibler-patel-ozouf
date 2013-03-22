
#include	"ActionEvent.hpp"
#include	"SnakePart.hh"
#include	"Trame.hh"
#include	"Snake.hh"

#include	"Debug.hh"

Snake::Snake(Rect *pos, int type, Map *map, Rect *tile):
  AStaticEntity("snake", pos, type, map, tile)
{
  this->speed = 1;
  if (tile)
    this->speed = tile->getPos().first;
  this->direction = BOTTOM;
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
  if (this->direction == LEFT)
    setDirection(BOTTOM);
  else if (this->direction == RIGHT)
    setDirection(TOP);
  else if (this->direction == TOP)
    setDirection(LEFT);
  else
    setDirection(RIGHT);
}

void	Snake::move_right(const std::string &)
{
  if (this->direction == LEFT)
    setDirection(TOP);
  else if (this->direction == RIGHT)
    setDirection(BOTTOM);
  else if (this->direction == TOP)
    setDirection(RIGHT);
  else
    setDirection(LEFT);
}

void	Snake::updateQueue()
{
  std::pair<int, int>	prev = this->pos->getPos();
  std::pair<int, int>	tmp;

  e_dir	prev_dir = this->getDir();
  e_dir	tmp_dir;
  for (unsigned int i = 0; i < this->queue.size(); ++i)
    {
      tmp = this->queue[i]->getPos()->getPos();
      this->queue[i]->getPos()->setPos(prev);
      tmp_dir = this->queue[i]->getDir();
      this->queue[i]->setDir(prev_dir);
      prev_dir = tmp_dir;
      prev = tmp;
    }
  prev_dir = this->getDir();
  for (unsigned int i = 1; i < this->queue.size(); ++i)
    {
      this->queue[i]->checkCorner(prev_dir, this->queue[i - 1]);
      prev_dir = this->queue[i]->getDir();
    }
}

void	Snake::move()
{
  int	x = this->pos->getPos().first;
  int	y = this->pos->getPos().second;
  
  int	tmpx, tmpy;

  this->updateQueue();
  
  if (this->direction == LEFT)
    {
      tmpx = x - this->speed;
      tmpy = y;
    }
  else if (this->direction == RIGHT)
    {
      tmpx = x + this->speed;
      tmpy = y;
    }
  else if (this->direction == TOP)
    {
      tmpx = x;
      tmpy = y - this->speed;
    }
  else
    {
      tmpx = x;
      tmpy = y + this->speed;
    }
  
  std::vector<std::string>	s_targets;
  std::vector<std::string>	s_args;
  
  s_targets.push_back(std::string("*"));
  s_args = (new Rect(tmpx, tmpy))->posStr();  
  std::string	trame(Trame::buildTrame("collide",
					this->unique_id,
					s_targets,
					s_args));
  this->map->getHandleEvent()->emit(trame);
  for (unsigned int i = 0; i < this->queue.size(); ++i)
    this->queue[i]->collide(trame);
  this->pos->setPos(tmpx, tmpy);
  
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
  if (this->queue.size() > 0)
    {
      SnakePart	*n = new SnakePart(new Rect(this->queue[this->queue.size() - 1]->getPos()->getPos().first, this->queue[this->queue.size() - 1]->getPos()->getPos().second), 0, this->map, new Rect());
      n->setDir(this->queue[this->queue.size() - 1]->getDir());
      this->map->addEntity(5, n);
      this->queue.push_back(n);
    }
  else
    {
      SnakePart	*n = new SnakePart(new Rect(this->pos->getPos().first, this->pos->getPos().second + 1), 0, this->map, new Rect());
      this->map->addEntity(5, n);
      this->queue.push_back(n);
    }
}

void	Snake::eat(const std::string &)
{
  this->addPart();
}

void	Snake::init()
{
  // a ameliorer
  SnakePart *s = new SnakePart(new Rect(10, 9, 0 ,0), 5, this->map, 0);
  SnakePart *s1 = new SnakePart(new Rect(10, 8, 0 ,0), 5, this->map, 0);
  SnakePart *s2 = new SnakePart(new Rect(10, 7, 0 ,0), 5, this->map, 0);
  s->setDir(BOTTOM);
  s1->setDir(BOTTOM);
  s2->setDir(BOTTOM);
  this->queue.push_back(s);
  this->queue.push_back(s1);
  this->queue.push_back(s2);
  this->map->addEntity(5, s);
  this->map->addEntity(5, s1);
  this->map->addEntity(5, s2);
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
  events["eat"] = new ActionEvent<Snake>(&Snake::eat, this);
  return (events);
}

e_dir	Snake::getDir()	const
{
  return (this->direction);
}
