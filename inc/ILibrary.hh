#ifndef __ILIBRARY_H__
# define __ILIBRARY_H__

#include <iostream>
#include <exception>

#include "Map.hh"
#include "Config.hh"

class ILibrary
{
public:
  virtual ~ILibrary() {};

  virtual void		drawRect(Rect* rec) = 0;
  virtual void		init(Config const &config) = 0;
  virtual void		loop(Map const &map) = 0;
  virtual void		quit() = 0;
  virtual void		reload(Config const &config) = 0;
  virtual void		updateEvent(std::stack<std::string> event) = 0;
};

class ConfigLoadError : public std::exception
{
  std::string	       msg;
public:
  ConfigLoadError(std::string const &msg, std::string const &func, std::string const &line);
  virtual ~ConfigLoadError() throw();

  virtual const char	*what() const throw();
};

class DrawError : public std::exception
{
  std::string		msg;
public:
  DrawError(std::string const &msg, std::string const &func, std::string const &line);
  virtual ~DrawError() throw();

  virtual const char	*what() const throw();
};

#endif /* !__ILIBRARY_H__ */
