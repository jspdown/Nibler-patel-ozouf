
#include	"SnakePart.hh"
#include	"Trame.hh"
#include	"Snake.hh"

Snake::Snake(Rect &pos,
	     int type,
	     Map *map,
	     std::pair<int, int> unit_size,
	     std::pair<int, int> img_size,
	     unsigned int nbr_frame,
	     int speed) :
  AAnimateEntity(std::string("snake"),
		 pos,
		 type,
		 map,
		 unit_size,
		 img_size,
		 nbr_frame)
{
  this->direction = Snake::LEFT;
  this->speed = speed;
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
  std::pair<int, int>	prev = this->pos.getPos();
  std::pair<int, int>	tmp;
  for (unsigned int i = 1; i < this->queue.size(); ++i)
    {
      tmp = this->queue[i]->getPos().getPos();
      this->queue[i]->getPos().setPos(prev);
      prev = tmp;
    }
}

void	Snake::move(const std::string &)
{
  int	x = this->pos.getPos().first;
  int	y = this->pos.getPos().second;
  
  if (this->direction == Snake::LEFT)
    this->pos.setPos(x - this->speed, y);
  else if (this->direction == Snake::RIGHT)
    this->pos.setPos(x + this->speed, y);
  else if (this->direction == Snake::TOP)
    this->pos.setPos(x, y - this->speed);
  else
    this->pos.setPos(x, y + this->speed);
  this->updateQueue();
}

void	Snake::update()
{
  std::vector<std::string>	s_targets;
  std::vector<std::string>	s_args;
  s_targets.push_back(std::string("*"));
  s_args = this->pos.posStr();  
  this->map->getHandleEvent()->emit(Trame::buildTrame("collide",
						     this->unique_id,
						     s_targets,
						     s_args));
  this->move("now");
}

void	Snake::collide(const std::string &trame)
{
  if (Trame::getTransmitter(trame) == this->unique_id)
    return ;
  std::vector<std::string> args = Trame::getArgs(trame);

  if (args.size() == 4)
    {
      if (this->pos.is_inside(Rect(Trame::toInt(args[0]), 
				    Trame::toInt(args[1]), 
				    Trame::toInt(args[2]), 
				    Trame::toInt(args[3]))))
	{
	  std::vector<std::string>	s_targets;
	  std::vector<std::string>	s_args;
	  s_targets.push_back(std::string("theGame"));
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
  SnakePart	n(this->pos, 0, this->map, std::pair<int, int>(32, 32), std::pair<int, int>(32, 32), 1);
  this->map->addEntity(5, &n);
}

void	Snake::init()
{

}