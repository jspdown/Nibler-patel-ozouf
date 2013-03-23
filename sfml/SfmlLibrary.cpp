//
// SfmlLibrary.cpp for /home/vink/projet/cpp/Nibler-patel-ozouf/src/Library/Sfml/SfmlLibrary.cpp in /home/vink/projet/cpp/Nibler-patel-ozouf
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Mon Mar 18 17:54:58 2013 kevin platel
//

#include <map>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "SfmlLibrary.hh"

SfmlLibrary::SfmlLibrary()
  : mWin(sf::VideoMode(800, 600), "Nibler")
{
}

SfmlLibrary::~SfmlLibrary()
{
}

void	SfmlLibrary::init(std::string const &texture_path, std::vector<std::string> const &texture)
{
  for (unsigned int i = 0; i < texture.size(); i++)
    {
      sf::Texture *tmp = new sf::Texture();
      tmp->loadFromFile(texture_path + texture[i]);
      (this->aff)[texture[i]] = tmp;
    }
}

void	SfmlLibrary::drawRect(std::pair<int,int> const &pos, std::pair<int,int> const &size, std::string const &texture, std::string const &str)
{
  sf::Sprite s(*((this->aff)[texture]));
  sf::Text t(str);

  s.setPosition(pos.first * size.first, pos.second * size.second);
  s.setTextureRect(sf::IntRect(0, 0, size.first, size.second));
  t.setPosition(pos.first, pos.second);
  this->mWin.draw(s);
  this->mWin.draw(t);
}

void	SfmlLibrary::reload(std::string const &texture_path, std::vector<std::string> const &texture)
{
  this->init(texture_path, texture);
}

void		SfmlLibrary::updateEvent(std::stack<std::string> &e)
{
  while (this->mWin.pollEvent(this->event))
    {
      if (this->event.type == sf::Event::KeyPressed)
	{
	  if (this->event.key.code == (sf::Keyboard::Left))
	    e.push("left|id|snake||");
	  if (this->event.key.code == (sf::Keyboard::Right))
	    e.push("right|id|snake||");
	  if (this->event.key.code == (sf::Keyboard::Q))
	    e.push("quit|id|thegame||");
	  if (this->event.key.code == (sf::Keyboard::Escape))
	    e.push("quit|id|thegame||");
	}
    }
}

void		SfmlLibrary::update()
{
  this->mWin.display();
}

void	SfmlLibrary::quit()
{
  this->mWin.close();
}

extern "C"
{
  ILibrary*	create_lib()
  {
    return new SfmlLibrary();
  }
}
