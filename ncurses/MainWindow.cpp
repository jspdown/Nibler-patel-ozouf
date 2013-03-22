//
// MainWindow.cpp for /home/vink/projet/cpp/Nibler-patel-ozouf/ncurses/MainWindow.cpp in /home/vink
//
// Made by vink
// Login   <kevin platel@epitech.net>
//
// Started on  Mon Mar 18 14:36:41 2013 vink
// Last update Fri Mar 22 18:31:59 2013 vink
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
  noecho();
  keypad(stdscr, TRUE);
  curs_set(0);
}

ncurses::MainWindow::~MainWindow()
{
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
  timeout(0);
  return (getch());
}

void	ncurses::MainWindow::update()
{
  std::for_each(this->sub_win.begin(), this->sub_win.end(), updateWindow);
  refresh();
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
