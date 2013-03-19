//
// NcursesLib.cpp for /home/vink/projet/cpp/Nibler-patel-ozouf/src/Library/Ncurses/NcursesLib.cpp in /home/vink
//
// Made by vink
// Login   <kevin platel@epitech.net>
//
// Started on  Mon Mar 18 15:54:42 2013 vink
// Last update Tue Mar 19 20:08:11 2013 kevin platel
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

  for (unsigned int i = 0; i < texture.size(); i++)
    {
      std::pair<char, int> tmp;
      col = ncurses::MainWindow::getColor(COLOR_RED, COLOR_RED);
      std::ifstream file((texture_path + texture[i]).c_str(), std::ios::in);
      c = file.get();
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
  str[0] = this->aff[texture].first;
  this->win.print(str, pos.first, pos.second);
}

void		NcursesLibrary::quit()
{
}

void		NcursesLibrary::reload(std::string const &texture_path, std::vector<std::string> const &texture)
{
  this->init(texture_path, texture);
}

void		NcursesLibrary::updateEvent(std::stack<std::string> &)
{
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
