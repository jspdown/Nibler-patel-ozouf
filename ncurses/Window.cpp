//
// Window.cpp for /home/vink/projet/piscine/rush3/Window.cpp in /home/vink
//
// Made by vink
// Login   <vink@epitech.net>
//
// Started on  Sat Jan 26 12:15:33 2013 vink

//

#include "Window.hh"
#include "MainWindow.hh"

ncurses::Window::Window(size_t posX, size_t posY, size_t height, size_t width,
			unsigned int forground, unsigned int background)
  : x(posX), y(posY), height(height), width(width), forground(forground), background(background)
{
  this->win = newwin(this->height, this->width, this->y, this->x);
  box(this->win, 0, 0);
  this->ls = ' ';
  this->rs = ' ';
  this->ts = ' ';
  this->bs = ' ';
  this->tlc = ' ';
  this->trc = ' ';
  this->blc = ' ';
  this->brc = ' ';
  if (has_colors() != FALSE)
    {
      start_color();
      this->ind_color = ncurses::MainWindow::getColor(forground, background);
    }
  //  this->setBorder(' ');
}

ncurses::Window::~Window()
{
  wborder(this->win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
  wrefresh(this->win);
  delwin(this->win);
}

void	ncurses::Window::printColor(bool set) const
{
  if (has_colors() != FALSE)
    {
      if (set)
	wattron(this->win, COLOR_PAIR(this->ind_color));
      else
	wattroff(this->win, COLOR_PAIR(this->ind_color));
    }
}

void	ncurses::Window::setColor(unsigned int foreground, unsigned int background)
{
  this->forground = foreground;
  this->background = background;
  this->ind_color = ncurses::MainWindow::getColor(foreground, background);
}

void	ncurses::Window::update()
{
  wrefresh(this->win);
}

void	ncurses::Window::clean()
{
  werase(this->win);
}

void ncurses::Window::setX(size_t x)
{
  this->x = x;
  this->move(this->y, this->x);
}

void ncurses::Window::setY(size_t y)
{
  this->y = y;
  this->move(this->y, this->x);
}

void ncurses::Window::setHeight(size_t height)
{
  this->height = height;
  wborder(this->win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
  wresize(this->win, this->height, this->width);
  wborder(this->win, this->ls, this->rs, this->ts, this->bs, this->tlc, this->trc,
	this->blc, this->brc);
}

void ncurses::Window::setWidth(size_t width)
{
  this->width = width;
  wborder(this->win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
  wresize(this->win, this->height, this->width);
  wborder(this->win, this->ls, this->rs, this->ts, this->bs, this->tlc, this->trc,
	this->blc, this->brc);
}

size_t ncurses::Window::getX() const
{
  return this->x;
}

size_t ncurses::Window::getY() const
{
  return this->y;
}

size_t ncurses::Window::getHeight() const
{
  return this->height;
}

size_t ncurses::Window::getWidth() const
{
  return this->width;
}

void ncurses::Window::move(size_t y, size_t x)
{
  this->x = x;
  this->y = y;
  wborder(this->win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
  mvwin(this->win, this->y, this->x);
  wborder(this->win, this->ls, this->rs, this->ts, this->bs, this->tlc, this->trc,
	this->blc, this->brc);
}

void ncurses::Window::resize(size_t height, size_t width)
{
  this->height = height;
  this->width = width;
  wborder(this->win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
  wresize(this->win, this->height, this->width);
  wborder(this->win, this->ls, this->rs, this->ts, this->bs, this->tlc, this->trc,
	this->blc, this->brc);
}

void ncurses::Window::setCorner(unsigned char c)
{
  this->tlc = c;
  this->trc = c;
  this->blc = c;
  this->brc = c;
  wborder(this->win, this->ls, this->rs, this->ts, this->bs, this->tlc, this->trc,
	this->blc, this->brc);
}

void ncurses::Window::setCorner(unsigned char tlc, unsigned char trc, unsigned char blc, unsigned char brc)
{
  this->tlc = tlc;
  this->trc = trc;
  this->blc = blc;
  this->brc = brc;
  wborder(this->win, this->ls, this->rs, this->ts, this->bs, this->tlc, this->trc,
	this->blc, this->brc);

}

void ncurses::Window::setBorder(unsigned char c)
{
  this->ls = c;
  this->rs = c;
  this->ts = c;
  this->bs = c;
  this->printColor();
  wborder(this->win, this->ls, this->rs, this->ts, this->bs, this->tlc, this->trc,
	this->blc, this->brc);
  this->printColor(false);
}

void ncurses::Window::setBorder(unsigned char lr, unsigned char tb)
{
  this->ls = lr;
  this->rs = lr;
  this->ts = tb;
  this->bs = tb;
  wborder(this->win, this->ls, this->rs, this->ts, this->bs, this->tlc, this->trc,
	this->blc, this->brc);
}

void ncurses::Window::setBorder(unsigned char top, unsigned char bottom, unsigned char left, unsigned char right)
{
  this->ls = left;
  this->rs = right;
  this->ts = top;
  this->bs = bottom;
  wborder(this->win, this->ls, this->rs, this->ts, this->bs, this->tlc, this->trc,
	this->blc, this->brc);
}

int	ncurses::Window::getKey(int timeout)
{
  wtimeout(this->win, timeout);
  return (wgetch(this->win));
}

void ncurses::Window::print(std :: string const & str) const
{
  this->printColor();
  mvwprintw(this->win, 1, 1, str.c_str());
  this->printColor(false);
}

void ncurses::Window::print(std :: string const & str, size_t x, size_t y) const
{
  this->printColor();
  mvwprintw(this->win, x, y, str.c_str());
  this->printColor(false);
}

void ncurses::Window::print(std :: string const & str, int capacity) const
{
  this->printColor();
  wattron(this->win, capacity);
  mvwprintw(this->win, 1, 1, str.c_str());
  wattroff(this->win, capacity);
  this->printColor(false);
}

void ncurses::Window::print(std :: string const & str, int capacity, size_t x, size_t y) const
{
  this->printColor();
  wattron(this->win, capacity);
  mvwprintw(this->win, x, y, str.c_str());
  wattroff(this->win, capacity);
  this->printColor(false);
}
