#ifndef __UTILS_H__
# define __UTILS_H__

#include <iostream>
#include <vector>

std::vector<std::string> split_string(const std::string &s, char delim);
std::vector<std::string> split_string(const std::string &s, const std::string &delim);

#endif /* !__UTILS_H__ */
