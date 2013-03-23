//
// Engine.cpp for /home/vink/projet/cpp/Nibler-patel-ozouf/src/Library/Engine.cpp in /home/vink/projet/cpp/Nibler-patel-ozouf
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Mon Mar 18 17:25:26 2013 kevin platel
// Last update Sat Mar 23 18:50:54 2013 vink
//

#include <unistd.h>

#include "Trame.hh"
#include "Engine.hh"

#include	"Debug.hh"

Engine::Engine(std::string const &lib)
{
  ILibrary*	(*new_lib)();

  this->lib = NULL;
  std::cout << lib << std::endl;
  this->dhandle = dlopen(lib.c_str(), RTLD_LAZY);
  if (this->dhandle == NULL)
    throw LibraryLoadError("Error when loding library : " + std::string(dlerror()));
  new_lib = reinterpret_cast<ILibrary *(*)()>(dlsym(dhandle, "create_lib"));
  if (new_lib == NULL)
    throw LibraryLoadError("Error when loading creation symbol");
  this->lib = new_lib();
  std::cout << "Library loaded." << std::endl;
  this->the_end = false;
}

Engine::~Engine()
{
  delete this->lib;
  dlclose(this->dhandle)
;
}

void	Engine::init(Config const &conf)
{
  this->conf = &conf;
  if (this->lib)
    this->lib->init(conf.getTexturePath(), conf.getTexture());
}

void	Engine::quit()
{
}

void	Engine::run(Map &map)
{
  map.setEngine(this);
  map.getHandleEvent()->init();
  while (!(this->the_end))
    {
      this->lib->updateEvent(map.getEvent());
      std::vector< std::list<IEntity*> > const &  toAff = map.getElements();
      map.updateEvent();
      for (unsigned int i = 0; i < toAff.size(); ++i)
	{
	  map.updateEvent();
	  std::list<IEntity*>::const_iterator it = toAff[i].begin();
	  while (it != toAff[i].end())
	    {
	      (*it)->update();
	      this->lib->drawRect((*it)->getPos()->getPos(),
				  (*it)->getRect()->getSize(),
				  (*it)->getRect()->getTexture(),
				  (*it)->getRect()->getStr());
	      if ((*it)->getName() == "snake")
		Debug::write((*it)->getName().c_str(), (*it)->getPos()->getPos().first, (*it)->getPos()->getPos().second);
	      it++;
	    }
	}
      if (!(this->the_end))
	{
	  this->lib->update();
	  usleep(this->conf->getWaitTime());
	}
    }
}

void		Engine::setTheEnd(bool state)
{
  this->the_end = state;
}
