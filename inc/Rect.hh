#ifndef __RECT_H__
# define __RECT_H__

#include <iostream>
#include <pair>

class Rect
{
private:
  std::pair<int, int>	pos;
  std::pair<int, int>	size;
  std::string		str;
  std::string		texture;
public:
  Rect(int x = 0, int y = 0, int width = 0, int height = 0, std::string const &str = "", st::string const &texture = "");
  Rect(std::pair<int,int> const &pos, std::pair<int,int> const &size, std::string const &str = "", std::string const &texture = "");
  virtual ~Rect();

  std::pair<int.int>&	getPos() const;
  std::pair<int,int>&	getSize() const;
  std::string		getStr() const;
  std::string		getTexture() const;

  void			setPos(std::pair<int,int> const &pos);
  void			setPos(int x, int y);
  void			setSize(std::pair<int,int> const &size);
  void			setSize(int width, int height);
  void			setStr(std::string const &str);
  void			setTexture(std::string const &texture);

  void			state();
};

#endif /* !__RECT_H__ */
