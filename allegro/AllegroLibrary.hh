#ifndef __ALLEGROLIBRARY_H__
# define __ALLEGROLIBRARY_H__

#include <cstdio>
#include <map>

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_native_dialog.h"

#include "ILibrary.hh"

enum MYKEYS {
  KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};

class AllegroLibrary : public ILibrary
{
private:
  ALLEGRO_DISPLAY				*display;
  ALLEGRO_EVENT_QUEUE				*event_queue;
  std::map< std::string, ALLEGRO_BITMAP *>	aff;
public:
  AllegroLibrary();
  virtual ~AllegroLibrary();

  virtual void		drawRect(std::pair<int,int> const &pos, std::pair<int,int> const &size, std::string const &texture, std::string const &str);
  virtual void		init(std::string const &texture_path, std::vector<std::string> const &texture);
  virtual void		update();
  virtual void		quit();
  virtual void		reload(std::string const &texture_path, std::vector<std::string> const &texture);
  virtual void		updateEvent(std::stack<std::string> &event);
};

#endif /* !__SFMLLIBRARY_H__ */
