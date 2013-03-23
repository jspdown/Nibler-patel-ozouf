#ifndef __NCURSESLIB_H__
# define __NCURSESLIB_H__

#include <map>
#include "ILibrary.hh"
#include "MainWindow.hh"

class NcursesLibrary : public ILibrary
{
private:
  ncurses::MainWindow				mWin;
  ncurses::Window				win;
  std::map< std::string, std::pair<char, int> >	aff;
public:
  NcursesLibrary();
  virtual ~NcursesLibrary();

  virtual void		drawRect(std::pair<int,int> const &pos, std::pair<int,int> const &size, std::string const &texture, std::string const &str);
  virtual void		init(std::string const &texture_path, std::vector<std::string> const &texture);
  virtual void		update();
  virtual void		quit();
  virtual void		reload(std::string const &texture_path, std::vector<std::string> const &texture);
  virtual void		updateEvent(std::stack<std::string> &event);
};

#endif /* !__NCURSESLIB_H__ */
