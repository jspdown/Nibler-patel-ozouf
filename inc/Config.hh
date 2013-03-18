#ifndef __CONFIG_H__
# define __CONFIG_H__

#include <iostream>
#include <vector>
#include <utility>

class Config
{
private:
  std::pair<int,int>		map_size;
  std::vector<std::string>	texture;
  std::string			texture_path;
  std::pair<int,int>		tile_size;
  size_t			waitTime;
public:
  Config(int width, int height, std::vector<std::string> &texture, std::string const &texture_path, int width_tile, int height_tile, size_t wait_time);
  Config(std::pair<int,int> &size, std::vector<std::string> &texture, std::string const &texture_path, std::pair<int,int> &tile_size, size_t wait_time);
  virtual ~Config();

  std::pair<int,int>		getMapSize() const;
  std::vector<std::string>	getTexture() const;
  std::string			getTexturePath() const;
  std::pair<int,int>		getTileSize() const;
  size_t			getWaitTime() const;
};

#endif /* !__CONFIG_H__ */
