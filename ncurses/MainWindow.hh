#ifndef __MAINWINDOW_H__
# define __MAINWINDOW_H__

#include <iostream>
#include <deque>
#include <utility>
#include <vector>
#include <algorithm>
#include <ncurses.h>
#include "Window.hh"

namespace ncurses
{

  class MainWindow
  {
    std::deque<Window *>			sub_win;
    static std::vector< std::pair<int,int> >	color_pair;
  public:
    MainWindow();
    virtual ~MainWindow();
    static int		getColor(int forground, int background);
    void			addWindow(Window *win);
    ncurses::Window		*delWindow(Window *win);
    int			getCh();
    void		mainLoop();
    void		update();
};
}

#endif /* !__MAINWINDOW_H__ */
