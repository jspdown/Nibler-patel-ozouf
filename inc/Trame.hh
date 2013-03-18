
#ifndef		__TRAME_HH__
# define	__TRAME_HH__

#include	<sstream>
#include	<vector>
#include	<string>

class	Trame
{
public:
  class	TrameError: public	std::exception
  {
    std::string         msg;
  public:
    TrameError(const std::string &, int line);
    virtual ~TrameError() throw();
    virtual const char  *what() const throw();
  };

  static std::string			getName(const std::string& trame);
  static int				getTransmitter(const std::string& trame);
  static std::vector<std::string>	getTargets(const std::string& trame);
  static std::vector<std::string>	getArgs(const std::string& trame);

  static std::string			buildTrame(const std::string &name,
						   int transmitter,
						   std::vector<std::string> targets,
						   std::vector<std::string> args);
  static int				toInt(const std::string &str);
private:
  static std::vector<std::string>	split(const std::string &s, char c);
  
public:
  class	TrameBuffer
  {
    std::string		buffer;
  public:
    void	operator()(std::string s);
    void	putSeparator(char c);
    std::string	getBuffer()	const;
  };
};

#endif
