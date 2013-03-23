
#ifndef		__THEGAME_H__
# define	__THEGAME_H__

#include	"Map.hh"
#include	"AStaticEntity.hh"

class	TheGame: public AStaticEntity
{
  int	score;
public:
  TheGame(Map *map);
  virtual ~TheGame();

  void	endOfGame(const std::string &trame);
  void	quit(const std::string &trame);
  void	earnsPoints(const std::string &trame);

  virtual void	update();
  virtual void	init();
  virtual TheGame *clone(Rect *pos, int type, Map *map, Rect *r)	const;
  virtual std::map<std::string, IActionEvent *> generateEventListened();
};

#endif
