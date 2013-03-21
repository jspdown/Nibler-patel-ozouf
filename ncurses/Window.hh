#ifndef __IWINDOW_H__
# define __IWINDOW_H__

#include <iostream>
#include <ncurses.h>

namespace ncurses
{
  class Window
  {
  private:
    size_t	x;
    size_t	y;
    size_t	height;
    size_t	width;
    WINDOW*	win;
    unsigned char ls;
    unsigned char rs;
    unsigned char ts;
    unsigned char bs;
    unsigned char tlc;
    unsigned char trc;
    unsigned char blc;
    unsigned char brc;
    unsigned int  forground;
    unsigned int  background;
  unsigned int		ind_color;
    void	printColor(bool set = true) const;

  public:
    Window(size_t posX = 0, size_t posY = 0, size_t height = 20, size_t width = 20, unsigned int forground = COLOR_WHITE, unsigned int background = COLOR_BLACK);
    virtual ~Window();

    void	update();
    void	clean();

    void	setX(size_t x);
    void	setY(size_t y);
    void	setHeight(size_t height);
    void	setWidth(size_t width);

    size_t	getX() const;
    size_t	getY() const;
    size_t	getHeight() const;
    size_t	getWidth() const;

    void	move(size_t x, size_t y);
    void	resize(size_t height, size_t width);

    void	setColor(unsigned int foreground, unsigned int background);


    // Set the character use for bordering the window
    void	setBorder(unsigned char c);
    void	setBorder(unsigned char lr, unsigned char tb);
    void	setBorder(unsigned char top, unsigned char bottom, unsigned char left, unsigned char right);
    void	setCorner(unsigned char c);
    void	setCorner(unsigned char tlc, unsigned char trc, unsigned char blc, unsigned char brc);

    int		getKey(int timeout = -1); // get last key press on window


    // Print in window
    void	print(std::string const & str) const;
    void	print(std::string const & str, int capacity) const;
    void	print(std::string const & str, size_t x, size_t y) const;
    void	print(std::string const & str, int capacity, size_t x, size_t y) const;
  };
}


#endif /* !__IWINDOW_H__ */
