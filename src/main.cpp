//
// main.cpp for /home/vink/projet/cpp/Nibler-patel-ozouf/src/main.cpp in /home/vink
//
// Made by vink
// Login   <kevin platel@epitech.net>
//
// Started on  Mon Mar 18 22:07:15 2013 vink
// Last update Sun Mar 24 15:32:11 2013 vink
//

#include <iostream>
#include <vector>
#include "Map.hh"
#include "IEntity.hh"
#include "HandleEvent.hh"
#include "Config.hh"
#include "Engine.hh"

#include	"Debug.hh"
int main(int argc, char *argv[])
{
  if (argc >= 4)
    {
      std::vector<std::string> texture;

      texture.push_back("wall");
      //      texture.push_back("snakepart");
      texture.push_back("snakepart-left");
      texture.push_back("snakepart-right");
      texture.push_back("snakepart-top");
      texture.push_back("snakepart-bottom");

      texture.push_back("snakepart-queue-left");
      texture.push_back("snakepart-queue-right");
      texture.push_back("snakepart-queue-top");
      texture.push_back("snakepart-queue-bottom");

      texture.push_back("snake-left");
      texture.push_back("snake-right");
      texture.push_back("snake-top");
      texture.push_back("snake-bottom");

      texture.push_back("snakepart-top-right");
      texture.push_back("snakepart-right-top");
      texture.push_back("snakepart-top-left");
      texture.push_back("snakepart-left-top");

      texture.push_back("snake");
      texture.push_back("floor");
      texture.push_back("food");

      try
	{
	  Config	conf(10,10, texture, "./ressource/", 1, 1, 500000, argv[3]);
	  Map		map(&conf, (argc >= 5 ? argv[4] : "./ressource/map/map-1.conf"));
	  Engine	eng(argv[3]);
	  eng.init(conf);
	  eng.run(map);
	}
      catch (LibraryLoadError &e)
	{
	  std::cerr << "Library Error : " << e.what() << std::endl;
	}
      catch (ConfigLoadError &e)
	{
	  std::cerr << "Configuration Error : " << e.what() << std::endl;
	}
      catch (TextureError &e)
	{
	  std::cerr << "Texture Error : " << e.what() << std::endl;
	}
      catch (...)
	{
	  std::cerr << "Unexcepted Error occurred" << std::endl;
	}
      return (0);
    }
  std::cout << "Usage: " << argv[0] << " lib.so" << std::endl;
  return (1);
}
