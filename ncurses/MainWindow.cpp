//
// MainWindow.cpp for /home/vink/projet/cpp/Nibler-patel-ozouf/ncurses/MainWindow.cpp in /home/vink
//
// Made by vink
// Login   <kevin platel@epitech.net>
//
// Started on  Mon Mar 18 14:36:41 2013 vink
// Last update Mon Mar 18 15:39:50 2013 vink
//

#include "MainWindow.hh"

std::vector< std::pair<int,int> >	ncurses::MainWindow::color_pair;

void	updateWindow(ncurses::Window *win)
{
  win->update();
}

ncurses::MainWindow::MainWindow()
{
  initscr();
  cbreak();
  noecho();
}

ncurses::MainWindow::~MainWindow()
{
  while (!this->sub_win.empty())
    {
      delete this->sub_win.front();
      this->sub_win.pop_front();
    }
  clrtoeol();
  endwin();
}

int	ncurses::MainWindow::getColor(int forground, int background)
{
  std::pair<int,int>	t(forground, background);
  int	i;

  if ((std::find(color_pair.begin(), color_pair.end(), t)) == color_pair.end())
    {
      init_pair(color_pair.size(), forground, background);
      color_pair.push_back(t);
    }
  for (i = 0; t != color_pair[i]; i++);
  return (i);
}

void	ncurses::MainWindow::addWindow( Window *win)
{
  this->sub_win.push_back(win);
  updateWindow(win);
}

ncurses::Window*	ncurses::MainWindow::delWindow( ncurses::Window *win)
{
  std::deque< ncurses::Window *>::iterator	it;
  Window				*tmp = NULL;

  if ((it = std::find(this->sub_win.begin(), this->sub_win.end(), win)) != this->sub_win.end())
    {
      tmp = *it;
      this->sub_win.erase(it);
    }
  return (tmp);
}

int	ncurses::MainWindow::getCh()
{
  return (getch());
}

void	ncurses::MainWindow::mainLoop()
{
  std::for_each(this->sub_win.begin(), this->sub_win.end(), updateWindow);
  do
    {
      std::for_each(this->sub_win.begin(), this->sub_win.end(), updateWindow);
    }
  while (this->getCh() != 'q');
}
