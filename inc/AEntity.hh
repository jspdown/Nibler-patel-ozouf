
#ifndef		__AENTITY_H__
# define	__AENTITY_H__

#include	<utility>
#include	<string>
#include	<ctime>
#include	"Rect.hh"
#include	"IEntity.hh"

class	AEntity: public IEntity
{
  static int		id;
protected:
  clock_t		current_time;
  Map			*map;
  std::string		name;
  Rect			*pos;
  int			type;
  int			unique_id;

public:
  AEntity(const std::string &name, Rect *pos, int type, Map *map);
  virtual ~AEntity();
  AEntity(const AEntity &other);
  AEntity	&operator=(const AEntity &other);

  virtual void	state()		const;

  double			getTimeElapse()	const;
  void				updateTimer();
  int				getType()	const;
  int				getUniqueId()  	const;
  Rect				*getPos()	const;
  Map				*getMap()	const;

  void	setCurrentTime(const clock_t &current_time);
  void	setMap(Map *m);
  void	setName(const std::string &name);
  virtual void	setPos(Rect *pos);
  void	setType(int type);

  virtual const std::string &getName() const;
};

#endif
