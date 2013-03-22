//
// main.cpp for /home/vink/projet/cpp/Nibler-patel-ozouf/src/main.cpp in /home/vink
//
// Made by vink
// Login   <kevin platel@epitech.net>
//
// Started on  Mon Mar 18 22:07:15 2013 vink
// Last update Fri Mar 22 13:49:35 2013 vink
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
  if (argc == 2)
    {
      std::vector<std::string> texture;

      texture.push_back("wall");
      //      texture.push_back("snakepart");
      
      texture.push_back("snakepart-left");
      texture.push_back("snakepart-right");
      texture.push_back("snakepart-top");
      texture.push_back("snakepart-bottom");

      texture.push_back("snakepart-top-right");
      texture.push_back("snakepart-right-top");
      texture.push_back("snakepart-top-left");
      texture.push_back("snakepart-left-top");

      texture.push_back("snake");
      texture.push_back("floor");
      texture.push_back("food");

      Config	conf(10,10, texture, "./ressource/", 1, 1, 500000, argv[1]);
      Map		map(&conf, "./ressource/map/map-1.conf");
      Engine	eng(argv[1]);
      eng.init(conf);
      eng.run(map);

      return (0);
    }
  std::cout << "Usage: " << argv[0] << " lib.so" << std::endl;
  return (1);
}
