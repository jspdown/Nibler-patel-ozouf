#ifndef __NCURSESLIB_H__
# define __NCURSESLIB_H__

#include <map>
#include "ILibrary.hh"
#include "MainWindow.hh"

class NcursesLibrary : public ILibrary
{
private:
  ncurses::MainWindow				mWin;
  const Config					*conf;
  Map						*map;
  std::map< std::string, std::pair<char, int> >	aff;
public:
  NcursesLibrary();
  virtual ~NcursesLibrary();

  void		drawRect(Rect* rec);
  void		init(Config const &config);
  void		loop(Map const &config);
  void		quit();
  void		reload(Config const &config);
  void		updateEvent(std::stack<std::string> &event);
};

#endif /* !__NCURSESLIB_H__ */
