//
// Engine.cpp for /home/vink/projet/cpp/Nibler-patel-ozouf/src/Library/Engine.cpp in /home/vink/projet/cpp/Nibler-patel-ozouf
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Mon Mar 18 17:25:26 2013 kevin platel
// Last update Wed Mar 20 21:20:58 2013 vink
//

#include <unistd.h>

#include "Trame.hh"
#include "Engine.hh"

#include	"Debug.hh"
Engine::Engine(std::string const &lib)
{
  ILibrary*	(*new_lib)();
  this->dhandle = dlopen(lib.c_str(), RTLD_LAZY);
  if (this->dhandle == NULL)
    throw LibraryLoadError("Error when loding library");
  new_lib = reinterpret_cast<ILibrary *(*)()>(dlsym(dhandle, "create_lib"));
  if (new_lib == NULL)
    throw LibraryLoadError("Error when loding creation symbol");
  this->lib = new_lib();
}

void	Engine::init(Config const &conf)
{
  this->conf = &conf;
  this->lib->init(conf.getTexturePath(), conf.getTexture());
}

void	Engine::quit()
{
}

void	Engine::run(Map &map)
{
  std::vector< std::list<IEntity*> > const &  toAff = map.getElements();

  while (1) // change to quit event
    {
      this->lib->updateEvent(map.getEvent());
      Debug::write("inside loop");
      for (unsigned int i = 0; i < toAff.size(); ++i)
	{
	  std::list<IEntity*>::const_iterator it = toAff[i].begin();
	  while (it != toAff[i].end())
	    {
	      (*it)->update();
	      this->lib->drawRect((*it)->getRect()->getPos(),
			     (*it)->getRect()->getSize(),
			     (*it)->getRect()->getTexture());
	      it++;
	    }
	}
      this->lib->update();
      usleep(this->conf->getWaitTime());
    }
}
