#include "catch.hpp"
#include "toolbox_web.h"

TEST_CASE("Urlencode RFC1738", "[urlencode]")
{
   std::string data{"My keyboard has ! @ # $ % ^ & * ( ) _ - + = { } | \\ : ; \" ' < , > . ? / ~ ` charcters"};
   REQUIRE(urlencode(data) == "My+keyboard+has+%21+%40+%23+%24+%25+%5E+%26+%2A+%28+%29+_+-+%2B+%3D+%7B+%7D+%7C+%5C+%3A+%3B+%22+%27+%3C+%2C+"
                              "%3E+.+%3F+%2F+%7E+%60+charcters");
}

TEST_CASE("Urlencode RFC3986", "[urlencode]")
{
   std::string data{"My keyboard has ! @ # $ % ^ & * ( ) _ - + = { } | \\ : ; \" ' < , > . ? / ~ ` charcters"};
   REQUIRE(urlencode(data, EncodingType::RFC3986) ==
           "My%20keyboard%20has%20%21%20%40%20%23%20%24%20%25%20%5E%20%26%20%2A%20%28%20%29%20_%20-%20%2B%20%3D%20%7B%20%7D%20%7C%20%5C%20%"
           "3A%20%3B%20%22%20%27%20%3C%20%2C%20%3E%20.%20%3F%20%2F%20%7E%20%60%20charcters");
}
