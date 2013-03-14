//
// Config.cpp for /home/vink/projet/cpp/Nibbler/src/Config.cpp in /home/vink
//
// Made by vink
// Login   <kevin platel@epitech.net>
//
// Started on  Wed Mar 13 09:50:00 2013 vink

//

#include <iostream>
#include "Config.hh"

Config::Config(int width, int height, std::vector<std::string> &texture, std::string const &texture_path, int width_tile, int height_tile)
{
  this->map_size.first = with;
  this->map_size.second = height;
  this->texture = texture;
  this->texture_path = texture_path;
  this->tile_size.first = width_tile;
  this->tile_size.second = height_tile;
}

Config::Config(std::pair<int,int> &size, std::vector<std::string> &texture, std::string const &texture_path, std::pair<int,int> &tile_size)
{
  this->map_size = size;
  this->texture = texture;
  this->texture_path = texture_path;
  this->tile_size = tile_size;
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
