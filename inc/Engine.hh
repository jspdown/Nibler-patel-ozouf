#ifndef __ENGINE_H__
# define __ENGINE_H__

#include <iostream>
#include <dlfcn.h>
#include "ILibrary.hh"
#include "Config.hh"

class Engine
{
  ILibrary*	lib;
  void		*dhandle;

public:
  Engine(std::string const &lib);
  virtual ~Engine();

  void	init(Config const *conf);
  void	quit();
  void	run(Map const *map);
};

class LibraryLoadError : public std::exception
{
  std::string	       msg;
public:
  LibraryLoadError(std::string const &msg, std::string const &func, std::string const &line);
  virtual ~LibraryLoadError() throw();

  virtual const char	*what() const throw();
};

#endif /* !__ENGINE_H__ */
