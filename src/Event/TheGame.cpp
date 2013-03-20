
#include	"ActionEvent.hpp"
#include	"TheGame.hh"

TheGame::TheGame(Map *map):
  AStaticEntity(std::string("theGame"), *(new Rect()), 0, map, new Rect()) 
{
  
}

TheGame::~TheGame()
{

}

void	TheGame::endOfGame(const std::string &)
{
  std::deque<Rect *>	menu;

  menu.push_back(new Rect(50, 50, 500, 500, "", "black.png"));
  menu.push_back(new Rect(150, 150, 150, 150, "Game Over", "white.png"));
  this->map->setAuxDisplay(this->unique_id, menu);
}

void	TheGame::quit(const std::string &)
{
  std::cout << "je quit" << std::endl;
}

void	TheGame::update()
{
  
}

void	TheGame::init()
{
  
}

TheGame *TheGame::clone(Rect &, int , Map *map, Rect *)	const
{
  return (new TheGame(map));
}

std::map<std::string, IActionEvent *> TheGame::generateEventListened()
{
  std::map<std::string, IActionEvent *>	events;

  events["endofgame"] = new ActionEvent<TheGame>(&TheGame::endOfGame, this);
  events["quit"] = new ActionEvent<TheGame>(&TheGame::quit, this);
  return (events);
}

