#ifndef __ILIBRARY_H__
# define __ILIBRARY_H__

#include <iostream>
#include <exception>
#include <utility>
#include <stack>
#include <vector>

class ILibrary
{
public:
  virtual ~ILibrary() {};

  virtual void		drawRect(std::pair<int,int> const &pos, std::pair<int,int> const &size, std::string const &texture, std::string const &str) = 0;
  virtual void		init(std::string const &texture_path, std::vector<std::string> const &texture) = 0;
  virtual void		update() = 0;
  virtual void		quit() = 0;
  virtual void		reload(std::string const &texture_path, std::vector<std::string> const &texture) = 0;
  virtual void		updateEvent(std::stack<std::string> &event) = 0;
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
