
#ifndef		__ASTATICENTITY_HH__
# define	__ASTATICENTITY_HH__

#include	<string>
#include	<utility>
#include	"Map.hh"
#include	"AEntity.hh"
#include	"Rect.hh"

class AStaticEntity : public AEntity
{
  Rect	*rect;
public:
  AStaticEntity(const std::string &name, std::pair<int, int> &pos, int type, Map *map, Rect *r);
  virtual ~AStaticEntity();
  AStaticEntity(const AStaticEntity &other);
  AStaticEntity	&operator=(const AStaticEntity &other);

  virtual Rect	*getRect()	const = 0;
};

#endif
