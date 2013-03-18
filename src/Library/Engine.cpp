//
// Engine.cpp for /home/vink/projet/cpp/Nibler-patel-ozouf/src/Library/Engine.cpp in /home/vink/projet/cpp/Nibler-patel-ozouf
//
// Made by kevin platel
// Login   <platel_k@epitech.net>
//
// Started on  Mon Mar 18 17:25:26 2013 kevin platel
// Last update Mon Mar 18 17:40:31 2013 kevin platel
//

#include "Engine.hh"

Engine::Engine(std::string const &lib)
{
  ILibrary*	(*new_lib)();
  this->dhandle = dlopen(lib.c_str(), RTLD_LAZY);
  if (this->dhandle == NULL)
    throw LibraryLoadError("Error when loding library", __FUNC__, __LINE__);
  new_lib = reinterpret_cast<ILibrary *(*)()>(dlsym(dhandle, "create_lib"));
  if (new_lib == NULL)
    throw LibraryLoadError("Error when loding creation symbol");
  this->lib = new_lib();
}

void	Engine::init(Config const *conf)
{
  this->lib->init(conf);
}

void	Engine::quit()
{
}

void	Engine::run(Map const *map)
{
  this->lib->loop(map);
}
