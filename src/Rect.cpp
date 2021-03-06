//
// Rect.cpp for /home/vink/projet/cpp/Nibbler/src/Rect.cpp in /home/vink
//
// Made by vink
// Login   <kevin platel@epitech.net>
//
// Started on  Tue Mar 12 22:59:45 2013 vink
// Last update Tue Mar 19 16:37:12 2013 vink
//

#include <iostream>
#include <utility>
#include <sstream>

#include "Rect.hh"

Rect::Rect(int x, int y, int width, int height, std::string const &str, std::string const &texture)
{
  this->pos.first = x;
  this->pos.second = y;

  this->size.first = width;
  this->size.second = height;

  this->str = str;
  this->texture = texture;
}

Rect::Rect(std::pair<int,int> const &pos, std::pair<int,int> const &size, std::string const &str, std::string const &texture)
{
  this->pos = pos;

  this->size = size;

  this->str = str;
  this->texture = texture;
}

Rect::~Rect()
{
}

std::pair<int,int> const &	Rect::getPos() const
{
  return (this->pos);
}

std::pair<int,int> const &	Rect::getSize() const
{
  return (this->size);
}

std::string		Rect::getStr() const
{
  return (this->str);
}

std::string		Rect::getTexture() const
{
  return (this->texture);
}

void			Rect::setPos(std::pair<int,int> const &pos)
{
  this->pos = pos;
}

void			Rect::setPos(int x, int y)
{
  this->pos.first = x;
  this->pos.second = y;
}

void			Rect::setSize(std::pair<int,int> const &size)
{
  this->size = size;
}

void			Rect::setSize(int width, int height)
{
  this->size.first = width;
  this->size.second = height;
}

void			Rect::setStr(std::string const &str)
{
  this->str = str;
}

void			Rect::setTexture(std::string const &texture)
{
  this->texture = std::string(texture);
}

void			Rect::state()
{
  std::cout << "Rect : x = " << this->pos.first << ", y = " << this->pos.second;
  std::cout << ", width = " << this->size.first << ", height = " << this->size.second;
  std::cout << ", str = [" << this->str << "], texture = [" << this->texture << "];" << std::endl;
}

bool			Rect::is_inside(const Rect &other)
{
  if (this->pos.first == other.getPos().first && this->pos.second == other.getPos().second)
    return (true);
  return (false);
}

std::vector<std::string>	Rect::posStr()	const
{
  std::stringstream	ss;
  std::stringstream	ss2;
  std::string		l;
  std::vector<std::string>	res;

  ss << this->pos.first;
  ss >> l;
  res.push_back(l);
  ss2 << this->pos.second;
  ss2 >> l;
  res.push_back(l);
  res.push_back(l);
  res.push_back(l);
  return (res);
}
