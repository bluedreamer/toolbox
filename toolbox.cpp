#include "toolbox.h"

auto trim(std::string &str) -> void
{
   str.erase(0, str.find_first_not_of(" \t\n\r"));
   str.erase(str.find_last_not_of(" \t\n\r") + 1);
}

auto find_and_replace(std::string &data, const std::string &find, const std::string &replace) -> void
{
   auto pos = data.find(find);
   while(pos != std::string::npos)
   {
      data.replace(pos, find.size(), replace);
      pos = data.find(find, pos + replace.size());
   }
}
