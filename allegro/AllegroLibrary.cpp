//
// AllegroLibrary.cpp for /home/vink/projet/cpp/Nibler-patel-ozouf/src/Library/Allegro/AllegroLibrary.cpp in /home/vink/projet/cpp/Nibler-patel-ozouf
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Mon Mar 18 17:54:58 2013 kevin platel
//

#include <map>
#include "AllegroLibrary.hh"

AllegroLibrary::AllegroLibrary()
{
  this->display = 0;
  std::cout << "Try to init allegro..." << std::endl;
  if (!al_init())
    throw ConfigLoadError("Error : can't init display");
  if(!al_init_image_addon())
    throw ConfigLoadError("Failed to init img addon");
  if(!al_install_keyboard())
    throw ConfigLoadError("Fail to init key");
  this->event_queue = al_create_event_queue();
  al_register_event_source(this->event_queue, al_get_keyboard_event_source());
  this->display = al_create_display(800, 600);
  if (!this->display)
    throw ConfigLoadError("Error : can't create display");

  al_clear_to_color(al_map_rgb(0,0,0));
}

AllegroLibrary::~AllegroLibrary()
{
  al_destroy_display(this->display);
}

void	AllegroLibrary::init(std::string const &texture_path, std::vector<std::string> const &texture)
{
  for (unsigned int i = 0; i < texture.size(); i++)
    {
      ALLEGRO_BITMAP *img = al_load_bitmap((texture_path + texture[i] + ".bmp").c_str());
      if (img)
	(this->aff)[texture[i]] = img;
    }
}

void	AllegroLibrary::drawRect(std::pair<int,int> const &pos, std::pair<int,int> const &size, std::string const &texture, std::string const &)
{
  if (this->aff[texture])
    al_draw_bitmap_region(this->aff[texture],0,0,size.first, size.second, pos.first * size.first ,pos.second * size.second, 0);
}

void	AllegroLibrary::reload(std::string const &texture_path, std::vector<std::string> const &texture)
{
  this->init(texture_path, texture);
}

void		AllegroLibrary::updateEvent(std::stack<std::string> &e)
{
  ALLEGRO_EVENT ev;
  ALLEGRO_TIMEOUT timeout;

  al_init_timeout(&timeout, 0.06);
  al_wait_for_event_until(this->event_queue, &ev, &timeout);
  if(ev.type == ALLEGRO_EVENT_KEY_DOWN)
    {
      if (ev.keyboard.keycode == ALLEGRO_KEY_LEFT)
	e.push("left|id|snake||");
      if (ev.keyboard.keycode == ALLEGRO_KEY_RIGHT)
	e.push("right|id|snake||");
      if (ev.keyboard.keycode == ALLEGRO_KEY_Q)
	e.push("quit|id|thegame||");
      if (ev.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
	e.push("quit|id|thegame||");
    }
}

void		AllegroLibrary::update()
{
  al_flip_display();
}

void	AllegroLibrary::quit()
{
}

extern "C"
{
  ILibrary*	create_lib()
  {
    return new AllegroLibrary();
  }
}
