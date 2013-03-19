//
// main.cpp for /home/vink/projet/cpp/Nibler-patel-ozouf/src/main.cpp in /home/vink
//
// Made by vink
// Login   <kevin platel@epitech.net>
//
// Started on  Mon Mar 18 22:07:15 2013 vink
// Last update Tue Mar 19 14:44:47 2013 vink
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
  HandleEvent e(new Listener(NULL));
  std::vector<std::string> texture;
  Engine	eng(argv[1]);

  texture.push_back("wall");
  texture.push_back("snakepart");
  Config	conf(10,10, texture, "./ressource/texture", 1, 1, 50);
  Map		map(&e, &conf, "./ressource/map/map-1.conf");

  eng.init(conf);
  eng.run(map);
  return 0;
}
