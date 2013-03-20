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

#include	"Debug.hh"
int main(int argc, char *argv[])
{
  Debug::write("\n\n######################-begin-###############");
  if (argc == 2)
    {
      Debug::write("args ok");
      std::vector<std::string> texture;
      Engine	eng(argv[1]);
      Debug::write("init engine");
      
      texture.push_back("wall");
      texture.push_back("snakepart");
      Debug::write("push des texture ok");
      Config	conf(10,10, texture, "./ressource/ntexture/", 1, 1, 50000);
      Debug::write("config ok");
      Map		map(&conf, "./ressource/map/map-1.conf");
      Debug::write("map ok");
      
      Debug::write("prepare init");
      eng.init(conf);
      Debug::write("init ok");
      Debug::write("prepare run");
      eng.run(map);
      Debug::write("run ok");

      return (0);
    }
  std::cout << "Usage: " << argv[0] << " lib.so" << std::endl;
  return (1);
}
