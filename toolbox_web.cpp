#include <iomanip>
#include <sstream>

#include "toolbox_web.h"

std::string urlencode(const std::string &str, EncodingType type)
{
   std::ostringstream strm;
   for(char c : str)
   {
      if(std::isalnum(c) || c == '-' || c == '_' || c == '.')
      {
         strm << c;
      }
      else if(c == ' ' && type == EncodingType::RFC1738)
      {
         strm << '+';
      }
      else
      {
         strm << '%' << std::setfill('0') << std::setw(2) << std::uppercase << std::hex << (int)c;
      }
   }
   return strm.str();
}

std::string http_build_query(const std::unordered_map<std::string, std::string> &data, EncodingType type)
{
   std::ostringstream strm;
   std::string        seperator;
   for(const auto &[key, value] : data)
   {
      strm << seperator << urlencode(key, type);
      if(!value.empty())
      {
         strm << "=" << urlencode(value, type);
      }
      seperator = '&';
   }
   return strm.str();
}
