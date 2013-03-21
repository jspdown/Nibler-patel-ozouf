
#include	<sstream>
#include	<string>
#include	<fstream>
#include	"Debug.hh"

void	Debug::write(const char *str, int x, int y)
{
  std::fstream filestr ("debug.txt", std::fstream::in | std::fstream::out | std::fstream::app);

  std::stringstream	ss;
  std::stringstream	ss2;
  std::string a1;
  std::string a2;
  ss << x;
  ss >> a1;
  ss2 << y;
  ss2 >> a2;

  std::string res;
  res = std::string(str) + std::string(" ") + a1 + std::string(" ") + a2 + std::string("|");
  filestr << res << std::endl;
  filestr.close();
}
