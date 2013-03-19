//
// SfmlLibrary.cpp for /home/vink/projet/cpp/Nibler-patel-ozouf/src/Library/Sfml/SfmlLibrary.cpp in /home/vink/projet/cpp/Nibler-patel-ozouf
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Mon Mar 18 17:54:58 2013 kevin platel
// Last update Mon Mar 18 18:13:31 2013 kevin platel
//

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

SfmlLibrary::SfmlLibrary()
{
  this->conf = NULL;
  this->map = NULL;
}

SfmlLibrary::~SfmlLibrary()
{
}

void	SfmlLibrary::init(Config const *conf)
{
  this->conf = conf;
  std::string texture_path = conf->getTexturePath();
  std::vector<std::string> texture = conf->getTexture();
  std::fstream;

  for (unsigned int i = 0; i < texture.size(); i++)
    {
      sf::Texture t;
      t.loadFromFile(texture_path + texture[i]);
      this->aff[texture] = t;
    }
}

void	SfmlLibrary::drawRect(Rect *rect)
{
  sf::RectangleShape rectangle;
  std::pair<int, int>	&tmp = rec.getPos();

  rectangle.setTexture(this->aff[rect.getTexture]);
  rectangle.move(tmp.first, tmp.second);
  tmp = rec.getSize();
  rectangle.setSize(tmp.first, tmp.second);
  this->window.draw(rectangle);
}

void	SfmlLibrary::reload(Config const *config)
{
  this->init(config);
}

void	SfmlLibrary::loop()
{
  std::vector< std::list<IEntity*> >&	toAff = config->getElements();
  while (this->window.isOpen)
    {
      // this->map->getHandleEvent()->emit(Trame::buildTrame(c, -1, std::vector<std::string>, std::vector<std::string>));
      for (int i = 0; i < toAff.size(); ++i)
	{
	  std::list<IEntity*>::iterator it = toAff[i].begin();
	  while (it != toAff[i].end())
	    {
	      (*it).update();
	      this->drawRect((*it).getRect());
	      it++;
	    }
	}
      this->window.clear();
      this->window.display();
      usleep(this->conf->getWaitTime());
    }
}

extern "C"
{
  ILibrary*	create_lib()
  {
    return new SfmlLibrary();
  }
}
