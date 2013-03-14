
#ifndef		__AENTITY_H__
# define	__AENTITY_H__

#include	<utility>
#include	<string>
#include	<ctime>
#include	"Map.hh"
#include	"Rect.hh"
#include	"IEntity.hh"

class	AEntity: public IEntity
{
  static int		id;

  clock_t		current_time;
  Map			*map;
  std::string		name;
  std::pair<int, int>	pos;
  int			type;
  int			unique_id;

public:
  AEntity(const std::string &name, std::pair<int, int> &pos, int type, Map *map);
  virtual ~AEntity();
  AEntity(const AEntity &other);
  AEntity	&operator=(const AEntity &other);

  virtual Rect	*getRect()	const = 0;
  virtual void	state()		const;
  
  double	getTimeElapse()	const;
  void		updateTimer()	const;
  int			getType()	const;
  int			getUniqueId()  	const;
  std::string		&getName()	const;
  std::pair<int, int>	&getPos()	const;
  Map			&getMap()	const;
};

#endif
