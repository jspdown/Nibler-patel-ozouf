#include	"AStaticEntity.hh"

AStaticEntity::AStaticEntity(const std::string &name, Rect &pos, int type, Map *map, Rect *tile):
  AEntity(name, pos, type, map), rect(tile)
{

}

AStaticEntity::~AStaticEntity()
{

}
AStaticEntity::AStaticEntity(const AStaticEntity &other):
  AEntity(other), rect(other.getRect())
{

}

AStaticEntity	&AStaticEntity::operator=(const AStaticEntity &other)
{
  AEntity::operator=(other);
  this->rect = other.getRect();
  return (*this);
}
