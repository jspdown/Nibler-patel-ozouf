/*
** main_test.c for /home/vink/projet/cpp/Nibler-patel-ozouf/ncurses/main_test.c in /home/vink
**
** Made by vink
** Login   <kevin platel@epitech.net>
**
** Started on  Mon Mar 18 12:24:03 2013 vink
** Last update Mon Mar 18 15:46:42 2013 vink
*/

#include <ncurses.h>
#include "Window.hh"
#include "MainWindow.hh"

int main(int argc, char *argv[])
{
  ncurses::MainWindow	m;
  ncurses::Window	*win = new ncurses::Window();

  m.addWindow(win);
  win->move(2, 2);
  win->setColor(COLOR_RED, COLOR_BLUE);
  win->setBorder(' ');
  win->setColor(COLOR_GREEN, COLOR_GREEN);
  win->setBorder(' ');
  win->setColor(COLOR_GREEN, COLOR_BLACK);
  win->print("Salut");
  win->setColor(COLOR_BLUE, COLOR_BLACK);
  win->print("Salut", 3, 3);
  win->setColor(COLOR_RED, COLOR_BLACK);
  win->print("Salut", 4, 4);
  m.mainLoop();
  return 0;
}
