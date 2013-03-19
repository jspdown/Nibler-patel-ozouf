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

void	SfmlLibrary::drawRect(std::pair<int,int> const &pos, std::pair<int,int> const &size, std::string const &texture)
{
  sf::Sprite s(*((this->aff)[texture]));

  s.setPosition(pos.first, pos.second);
  s.setTextureRect(sf::IntRect(0, 0, size.first, size.second));
  this->mWin.draw(s);
}

void	SfmlLibrary::reload(std::string const &texture_path, std::vector<std::string> const &texture)
{
  this->init(texture_path, texture);
}

void		SfmlLibrary::updateEvent(std::stack<std::string> &)
{
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
