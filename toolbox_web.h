#pragma once

#include <string>
#include <unordered_map>

enum class EncodingType
{
   RFC1738, // per RFC 1738 and the application/x-www-form-urlencoded media type, which implies that spaces are encoded as plus (+) signs.
   RFC3986, // per RFC 3986, and spaces will be percent encoded (%20).
};

auto urlencode(const std::string &str, EncodingType type = EncodingType::RFC1738) -> std::string;
auto http_build_query(const std::unordered_map<std::string, std::string> &data, EncodingType type = EncodingType::RFC1738) -> std::string;
