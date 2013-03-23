#ifndef __SFMLLIBRARY_H__
# define __SFMLLIBRARY_H__

#include <map>

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

#include "ILibrary.hh"

class SfmlLibrary : public ILibrary
{
private:
  sf::RenderWindow	mWin;
  sf::Event		event;
  std::map< std::string, sf::Texture* >	aff;
public:
  SfmlLibrary();
  virtual ~SfmlLibrary();

  virtual void		drawRect(std::pair<int,int> const &pos, std::pair<int,int> const &size, std::string const &texture, std::string const &str);
  virtual void		init(std::string const &texture_path, std::vector<std::string> const &texture);
  virtual void		update();
  virtual void		quit();
  virtual void		reload(std::string const &texture_path, std::vector<std::string> const &texture);
  virtual void		updateEvent(std::stack<std::string> &event);
};


#endif /* !__SFMLLIBRARY_H__ */
