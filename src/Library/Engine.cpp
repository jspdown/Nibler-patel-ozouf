//
// Engine.cpp for /home/vink/projet/cpp/Nibler-patel-ozouf/src/Library/Engine.cpp in /home/vink/projet/cpp/Nibler-patel-ozouf
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Mon Mar 18 17:25:26 2013 kevin platel
// Last update Thu Mar 21 15:28:14 2013 vink
//

#include <unistd.h>

#include "Trame.hh"
#include "Engine.hh"

#include	"Debug.hh"

Engine::Engine(std::string const &lib)
{
  ILibrary*	(*new_lib)();

  this->lib = NULL;
  this->dhandle = dlopen(lib.c_str(), RTLD_LAZY);
  if (this->dhandle == NULL)
    throw LibraryLoadError("Error when loding library");
  new_lib = reinterpret_cast<ILibrary *(*)()>(dlsym(dhandle, "create_lib"));
  if (new_lib == NULL)
    throw LibraryLoadError("Error when loding creation symbol");
<<<<<<< HEAD
  this->lib = new_lib();
  this->the_end = false;
=======
  //  this->lib = new_lib();
>>>>>>> 350999d876b22e7c8e418eeb16a87dde0ab0d2d1
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
  while (!(this->the_end))
    {
      //       this->lib->updateEvent(map.getEvent());
      std::vector< std::list<IEntity*> > const &  toAff = map.getElements();
<<<<<<< HEAD
      this->lib->updateEvent(map.getEvent());
      map.updateEvent();
      
=======
       map.updateEvent();
>>>>>>> 350999d876b22e7c8e418eeb16a87dde0ab0d2d1
      for (unsigned int i = 0; i < toAff.size(); ++i)
	{
	  map.updateEvent();
	  std::list<IEntity*>::const_iterator it = toAff[i].begin();
	  while (it != toAff[i].end())
	    {
	      (*it)->update();
<<<<<<< HEAD
	      
	      this->lib->drawRect((*it)->getPos()->getPos(),
			     (*it)->getRect()->getSize(),
			     (*it)->getRect()->getTexture());
	      Debug::write("rect", (*it)->getPos()->getPos().first, (*it)->getPos()->getPos().second);
=======
	      if ((*it)->getRect()->getTexture() == "snake")
		std::cout << (*it)->getPos() << std::endl;
	      //	      this->lib->drawRect((*it)->getRect()->getPos(),
	      //		     (*it)->getRect()->getSize(),
	      //		     (*it)->getRect()->getTexture());
	      Debug::write("rect", (*it)->getRect()->getPos().first, (*it)->getRect()->getPos().second);
>>>>>>> 350999d876b22e7c8e418eeb16a87dde0ab0d2d1
	      it++;
	    }
	}
      //      this->lib->update();
      usleep(this->conf->getWaitTime());
    }
}

void		Engine::setTheEnd(bool state)
{
  this->the_end = state;
}
