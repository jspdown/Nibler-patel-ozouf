
#ifndef		__ASTATICENTITY_HH__
# define	__ASTATICENTITY_HH__

#include	<string>
#include	<utility>
#include	"Map.hh"
#include	"AEntity.hh"
#include	"Rect.hh"

class AStaticEntity : public AEntity
{
protected:
  Rect	rect;
public:
  AStaticEntity(const std::string &name, Rect *pos, int type, Map *map, Rect *tile);
  virtual ~AStaticEntity();
  AStaticEntity(const AStaticEntity &other);
  AStaticEntity	&operator=(const AStaticEntity &other);

  virtual Rect 	const *getRect() const ;
};

#endif
