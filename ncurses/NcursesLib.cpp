//
// NcursesLib.cpp for /home/vink/projet/cpp/Nibler-patel-ozouf/src/Library/Ncurses/NcursesLib.cpp in /home/vink
//
// Made by vink
// Login   <kevin platel@epitech.net>
//
// Started on  Mon Mar 18 15:54:42 2013 vink
// Last update Fri Mar 22 16:42:43 2013 vink
//

#include <utility>
#include <fstream>
#include <unistd.h>
#include <ncurses.h>

#include "Trame.hh"

#include "Rect.hh"
#include "NcursesLib.hh"

NcursesLibrary::NcursesLibrary()
{
}

NcursesLibrary::~NcursesLibrary()
{
}

void		NcursesLibrary::init(std::string const &texture_path, std::vector<std::string> const &texture)
{
  char	c;
  int	col;
  char	a;

  for (unsigned int i = 0; i < texture.size(); i++)
    {
      std::pair<char, int> tmp;
      std::ifstream file((texture_path + texture[i]).c_str(), std::ios::in);
      c = file.get();
      if (file)
	a = file.get();
      else
	a = 0;
      col = ncurses::MainWindow::getColor(a, COLOR_BLACK);
      tmp.first = c;
      tmp.second = col;
      (this->aff)[texture[i]] = tmp;
      file.close();
    }
  this->win.resize(80, 80);
  this->mWin.addWindow(&this->win);
}

void		NcursesLibrary::drawRect(std::pair<int,int> const &pos, std::pair<int,int> const &size, std::string const &texture)
{
  char	str[2];

  str[1] = 0;
  if (this->aff.find(texture) != this->aff.end())
    str[0] = (this->aff[texture]).first;
  else
    str[0] = 'U';
  if (can_change_color() == TRUE)
    this->win.print(str, COLOR_PAIR((this->aff[texture]).second), pos.first, pos.second);
  else
    this->win.print(str, pos.first, pos.second);
}

void		NcursesLibrary::quit()
{
}

void		NcursesLibrary::reload(std::string const &texture_path, std::vector<std::string> const &texture)
{
  this->init(texture_path, texture);
}

void		NcursesLibrary::updateEvent(std::stack<std::string> &e)
{
  int	c;

  c = this->mWin.getCh();
  if (c == 'q')
    e.push("quit|id|thegame||");
  else if (c == KEY_LEFT)
    e.push("left|id|snake||");
  else if (c == KEY_RIGHT)
    e.push("right|id|snake||");
}

void		NcursesLibrary::update()
{
  this->mWin.update();
}

extern "C"
{
  ILibrary*	create_lib()
  {
    return new NcursesLibrary();
  }
}
