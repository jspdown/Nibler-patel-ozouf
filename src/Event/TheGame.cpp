
#include	<sstream>
#include	"Trame.hh"
#include	"ActionEvent.hpp"
#include	"TheGame.hh"

#include	"Debug.hh"

TheGame::TheGame(Map *map):
  AStaticEntity(std::string("theGame"), new Rect(), 0, map, new Rect()) 
{
  this->score = 0;
}

TheGame::~TheGame()
{
}

void	TheGame::endOfGame(const std::string &)
{
  std::deque<Rect *>	menu;

  Debug::write("endOfGame");
  menu.push_back(new Rect(50, 50, 500, 500, "", "wall"));
  menu.push_back(new Rect(150, 150, 150, 150, "Game Over", "snake"));
  this->map->setAuxDisplay(this->unique_id, menu);
}

void	TheGame::earnsPoints(const std::string &trame)
{
  std::vector<std::string> args = Trame::getArgs(trame);

  if (args.size() == 1)
    {
      std::stringstream	ss;
      int		value;
      ss << args[1];
      ss >> value;
  
      this->score += value;
    }
}

void	TheGame::quit(const std::string &)
{
  Debug::write("quit");
  this->map->getEngine()->setTheEnd(true);
}

void	TheGame::update()
{
  
}

void	TheGame::init()
{
  
}

TheGame *TheGame::clone(Rect *, int , Map *map, Rect *)	const
{
  return (new TheGame(map));
}

std::map<std::string, IActionEvent *> TheGame::generateEventListened()
{
  std::map<std::string, IActionEvent *>	events;

  events["endofgame"] = new ActionEvent<TheGame>(&TheGame::endOfGame, this);
  events["quit"] = new ActionEvent<TheGame>(&TheGame::quit, this);
  events["earnspoints"] = new ActionEvent<TheGame>(&TheGame::earnsPoints, this);
  return (events);
}

