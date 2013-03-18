//
// NcursesLib.cpp for /home/vink/projet/cpp/Nibler-patel-ozouf/src/Library/Ncurses/NcursesLib.cpp in /home/vink
//
// Made by vink
// Login   <kevin platel@epitech.net>
//
// Started on  Mon Mar 18 15:54:42 2013 vink
// Last update Mon Mar 18 21:41:49 2013 vink
//

#include <utility>
#include <fstream>
#include <unistd.h>

#include "Trame.hh"

#include "Rect.hh"
#include "NcursesLib.hh"

NcursesLibrary::NcursesLibrary()
{
  this->conf = NULL;
  this->map = NULL;
}

NcursesLibrary::~NcursesLibrary()
{
}

void		NcursesLibrary::init(Config const &conf)
{
  std::string texture_path = conf.getTexturePath();
  std::vector<std::string> texture = conf.getTexture();
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
}

void		NcursesLibrary::drawRect(Rect *rec)
{
  ncurses::Window	*new_win = new ncurses::Window();
  std::pair<int, int>	&tmp = rec->getPos();
  char	str[2];

  str[1] = 0;
  new_win->move(tmp.first, tmp.second);
  tmp = rec->getSize();
  new_win->resize(tmp.first, tmp.second);
  str[0] = this->aff[rec->getTexture()].first;
  new_win->print(str, this->aff[rec->getTexture()].second);
  this->mWin.addWindow(new_win);
}

void		NcursesLibrary::quit()
{

}

void		NcursesLibrary::reload(Config const &config)
{
  this->init(config);
}

void		NcursesLibrary::updateEvent(std::stack<std::string> &)
{

}

void		NcursesLibrary::loop(Map const &map)
{
  std::vector< std::list<IEntity*> >&	toAff = map.getElements();
  char	c[2];

  c[1] = 0;
  while ((c[0] = this->mWin.getCh()) != 'q')
    {
      map.getHandleEvent()->emit(Trame::buildTrame(c, -1, std::vector<std::string>(), std::vector<std::string>()));
      for (unsigned int i = 0; i < toAff.size(); ++i)
	{
	  std::list<IEntity*>::iterator it = toAff[i].begin();
	  while (it != toAff[i].end())
	    {
	      (*it)->update();
	      this->drawRect((*it)->getRect());
	      it++;
	    }
	}
      usleep(this->conf->getWaitTime());
    }
}

extern "C"
{
  ILibrary*	create_lib()
  {
    return new NcursesLibrary();
  }
}
