
#include	<string>
#include	<fstream>
#include	"Debug.hh"

void	Debug::write(const char *str)
{
  std::fstream filestr ("debug.txt", std::fstream::in | std::fstream::out|std::fstream::app);

  filestr << std::string(str) << std::endl;
  filestr.close();
}
