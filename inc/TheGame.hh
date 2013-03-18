
#ifndef		__THEGAME_H__
# define	__THEGAME_H__

#include	"Map.hh"
#include	"AStaticEntity.hh"

class	TheGame: public AStaticEntity
{
public:
  TheGame(Map *map);
  virtual ~TheGame();

  void	endOfGame(const std::string &trame);

  virtual void	update();
  virtual void	init();
};

#endif