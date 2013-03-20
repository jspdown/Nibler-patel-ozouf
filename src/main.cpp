//
// main.cpp for /home/vink/projet/cpp/Nibler-patel-ozouf/src/main.cpp in /home/vink
//
// Made by vink
// Login   <kevin platel@epitech.net>
//
// Started on  Mon Mar 18 22:07:15 2013 vink
// Last update Tue Mar 19 20:21:06 2013 kevin platel
//

#include <iostream>
#include <vector>
#include "Map.hh"
#include "IEntity.hh"
#include "HandleEvent.hh"
#include "Config.hh"
#include "Engine.hh"


int main(int argc, char *argv[])
{
  if (argc == 2)
    {
      std::vector<std::string> texture;
      //Engine	eng(argv[1]);
      
      texture.push_back("wall");
      texture.push_back("snakepart");
      Config	conf(10,10, texture, "./ressource/ntexture/", 1, 1, 50000);
      Map		map(&conf, "./ressource/map/map-1.conf");
      
      return (1);
      //eng.init(conf);
      //eng.run(map);
      return (0);
    }
  std::cout << "Usage: " << argv[0] << " lib.so" << std::endl;
  return (1);
}
