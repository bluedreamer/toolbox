#include "catch.hpp"
#include "toolbox_web.h"

TEST_CASE("Single key/value pair", "[html_build_query]")
{
   std::unordered_map<std::string, std::string> data{{"pageno", "42!=life"}};
   REQUIRE(http_build_query(data, EncodingType::RFC1738) == "pageno=42%21%3Dlife");
   REQUIRE(http_build_query(data, EncodingType::RFC3986) == "pageno=42%21%3Dlife");
}

TEST_CASE("Multiple key/value pairs", "[html_build_query]")
{
   std::unordered_map<std::string, std::string> data{
      {"pageno", "42"}, {"loggedin", "false"}, {"level", "no"}, {"location", "40000 leagues beneath the sea! #$%#$#%"}};
   REQUIRE(http_build_query(data, EncodingType::RFC1738) ==
           "location=40000+leagues+beneath+the+sea%21+%23%24%25%23%24%23%25&level=no&loggedin=false&pageno=42");
   REQUIRE(http_build_query(data, EncodingType::RFC3986) ==
           "location=40000%20leagues%20beneath%20the%20sea%21%20%23%24%25%23%24%23%25&level=no&loggedin=false&pageno=42");
}

TEST_CASE("Single key", "[html_build_query]")
{
   std::unordered_map<std::string, std::string> data{{"page # 23", ""}};
   REQUIRE(http_build_query(data, EncodingType::RFC1738) == "page+%23+23");
   REQUIRE(http_build_query(data, EncodingType::RFC3986) == "page%20%23%2023");
}

TEST_CASE("Multple keys", "[html_build_query]")
{
   std::unordered_map<std::string, std::string> data{{"value", ""}, {"paid for", ""}, {"godmode", ""}};
   REQUIRE(http_build_query(data, EncodingType::RFC1738) == "godmode&paid+for&value");
   REQUIRE(http_build_query(data, EncodingType::RFC3986) == "godmode&paid%20for&value");
}
