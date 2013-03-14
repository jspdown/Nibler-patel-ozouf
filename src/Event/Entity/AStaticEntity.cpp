
#include	"AStaticEntity.hh"

AStaticEntity::AStaticEntity(const std::string &name, std::pair<int, int> &pos, int type, Map *map, Rect *r):
  AEntity(name, pos, type, map), rect(r)
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
}
