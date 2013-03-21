#include	<algorithm>
#include	<sstream>
#include	"Trame.hh"

std::vector<std::string>	Trame::split(const std::string &s, char c)
{
  std::vector<std::string>	root;
  std::stringstream		ss(s);
  std::string			str;

  while (std::getline(ss, str, c))
    root.push_back(str);
  return (root);
}

std::string	Trame::getName(const std::string& trame)
{
  std::vector<std::string>	s = Trame::split(trame, '|');

  if (s.size() != 4)
    throw	Trame::TrameError("trame error, can't find a name", __LINE__);
  return (s[0]);
}

std::vector<std::string>	Trame::getTargets(const std::string& trame)
{
  std::vector<std::string>	s = Trame::split(trame, '|');

  if (s.size() != 4)
    throw	Trame::TrameError("trame error, can't find a targets", __LINE__);
  std::vector<std::string>	r = Trame::split(s[2], ':');

  return (r);
}

std::vector<std::string>	Trame::getArgs(const std::string& trame)
{
  std::vector<std::string>	s = Trame::split(trame, '|');

  if (s.size() != 4)
    throw	Trame::TrameError("trame error, can't find a args", __LINE__);
  std::vector<std::string>	r = Trame::split(s[3], ':');
  return (r);
}

int				Trame::getTransmitter(const std::string& trame)
{
  std::vector<std::string>	s = Trame::split(trame, '|');
  int				res;

  if (s.size() != 4)
    throw	Trame::TrameError("trame error, can't find a transmitter", __LINE__);
  std::stringstream	ss;
  ss << s[1];
  ss >> res;
  return (res);
}


std::string			Trame::buildTrame(const std::string &name,
					   int transmitter,
					   std::vector<std::string> targets,
					   std::vector<std::string> args)
{
  Trame::TrameBuffer	buff;
  std::string		tr;
  std::stringstream	ss;

  ss << transmitter;
  ss >> tr;
  buff(name);
  buff.putSeparator('|');
  buff(tr);
  buff.putSeparator('|');
  for (unsigned int i = 0; i < targets.size(); ++i)
    buff(targets[i]);
  buff.putSeparator('|');
  for (unsigned int i = 0; i < args.size(); ++i)
    buff(args[i]);
  buff.putSeparator('|');
  return (buff.getBuffer());
}

int				Trame::toInt(const std::string &str)
{
  int	res;
  std::stringstream	ss;

  ss << str;
  ss >> res;
  return (res);
}

void	Trame::TrameBuffer::operator()(std::string s)
{
  this->buffer.append(s + std::string(":"));
}

void	Trame::TrameBuffer::putSeparator(char c)
{
  this->buffer[this->buffer.size() - 1] = c;
}

std::string	Trame::TrameBuffer::getBuffer()	const
{
  return (this->buffer);
}

Trame::TrameError::TrameError(const std::string &, int line)
{
  std::stringstream    o;

  o << "[Trame] Error line " << line << " : " << msg;
  this->msg = o.str();
}
Trame::TrameError::~TrameError() throw()
{

}
const char  *Trame::TrameError::what() const throw()
{
  return (this->msg.c_str());
}
