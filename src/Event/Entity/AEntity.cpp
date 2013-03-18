
#include	<iostream>
#include	"AEntity.hh"

AEntity::AEntity(const std::string &name, std::pair<int, int> &pos, int type, Map *map) :
  map(map), name(name), pos(pos), type(type), unique_id(id)
{
  ++id;
}

AEntity::~AEntity()
{

}

AEntity::AEntity(const AEntity &other) :
  map(other.map), name(other.name), pos(other.pos), type(other.type), unique_id(id)
{
  ++id;
}

AEntity	&AEntity::operator=(const AEntity &other)
{
  this->map = other.getMap();
  this->name = other.getName();
  this->pos = other.getPos();
  this->type = other.getType();
  this->unique_id = id;
  ++id;
  return (*this);
}

void	AEntity::state()	const
{
  std::cout << "[Entity] state:["
	    << this->unique_id
	    << "] name = "
	    << this->name
	    << ", pos = ("
	    << this->pos.first
	    << ","
	    << this->pos.second
	    << "), type "
	    << this->type
	    << " ."
	    << std::endl;
}

double	AEntity::getTimeElapse()	const
{
  return ((clock() - this->current_time) / CLOCKS_PER_SEC);
}

void   	AEntity::updateTimer()
{
  this->current_time = clock();
}

int			AEntity::getType()	const
{
  return (this->type);
}

int			AEntity::getUniqueId()  	const
{
  return (this->unique_id);
}

std::string const		&AEntity::getName()	const
{
  return (this->name);
}

std::pair<int, int> const	&AEntity::getPos()	const
{
  return (this->pos);
}

Map			*AEntity::getMap()	const
{
  return (this->map);
}
