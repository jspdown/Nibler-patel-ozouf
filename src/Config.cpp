//
// Config.cpp for /home/vink/projet/cpp/Nibbler/src/Config.cpp in /home/vink
//
// Made by vink
// Login   <kevin platel@epitech.net>
//
// Started on  Wed Mar 13 09:50:00 2013 vink

//

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "Config.hh"
#include "utils.hh"

Config::Config(int width, int height, std::vector<std::string> &texture, std::string const &texture_path, int, int, unsigned int wait_time, std::string const &lib)
{
  std::stringstream ss;
  std::vector<std::string>	r;

  r = split_string(lib, "./_-");
  this->map_size.first = width;
  this->map_size.second = height;
  this->texture = texture;
  this->texture_path = texture_path  + r.at(r.size() - 2) + "/";
  std::fstream file((texture_path + r.at(r.size() - 2) + ".conf").c_str(), std::ios::in);
  file >> this->tile_size.first;
  file >> this->tile_size.second;
  this->waitTime = wait_time;
}

Config::Config(std::pair<int,int> &size, std::vector<std::string> &texture, std::string const &texture_path, std::pair<int,int> &, unsigned int wait_time, std::string const &lib)
{
  std::vector<std::string>	r;

  r = split_string(lib, "./_-");
  this->map_size = size;
  this->texture = texture;
  this->texture_path = texture_path  + r.at(r.size() - 2) + "/";
  std::ifstream file((texture_path + r.at(r.size() - 2) + ".conf").c_str(), std::ios::in);
  file >> this->tile_size.first;
  file >> this->tile_size.second;
  this->waitTime = wait_time;
}

Config::~Config()
{
}

std::pair<int,int>		Config::getMapSize() const
{
  return (this->map_size);
}

std::vector<std::string>	Config::getTexture() const
{
  return (this->texture);
}

std::string			Config::getTexturePath() const
{
  return (this->texture_path);
}

std::pair<int,int>		Config::getTileSize() const
{
  return (this->tile_size);
}

unsigned int			Config::getWaitTime() const
{
  return (this->waitTime);
}
