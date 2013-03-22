#include	"AStaticEntity.hh"

AStaticEntity::AStaticEntity(const std::string &name, Rect *pos, int type, Map *map, Rect *tile):
  AEntity(name, pos, type, map)
{
  this->rect.setPos(pos->getPos());
  if (tile)
    this->rect.setSize(tile->getPos());
  this->rect.setTexture(name);
}

AStaticEntity::~AStaticEntity()
{

}

AStaticEntity::AStaticEntity(const AStaticEntity &other):
  AEntity(other)
{
  this->rect = other.rect;
}

AStaticEntity	&AStaticEntity::operator=(const AStaticEntity &other)
{
  AEntity::operator=(other);
  this->rect = *(other.getRect());
  return (*this);
}

Rect	const *AStaticEntity::getRect() const
{
  return (&this->rect);
}
