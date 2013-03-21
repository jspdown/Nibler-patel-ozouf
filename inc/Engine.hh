#ifndef __ENGINE_H__
# define __ENGINE_H__

#include <iostream>
#include <dlfcn.h>
#include <exception>
#include "ILibrary.hh"
#include "Config.hh"

class Engine
{
  ILibrary*	lib;
  void		*dhandle;
  Config const	*conf;
public:
  Engine(std::string const &lib);
  virtual ~Engine();

  void	init(Config const &conf);
  void	quit();
  void	run(Map &map);
};

class LibraryLoadError : public std::exception
{
  std::string	       msg;
public:
  LibraryLoadError(std::string const &msg)
    : msg(msg)
  {
  }
  virtual ~LibraryLoadError() throw() {};

  virtual const char	*what() const throw() { return this->msg.c_str(); };
};

#endif /* !__ENGINE_H__ */
