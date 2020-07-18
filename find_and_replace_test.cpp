#include "catch.hpp"
#include "toolbox.h"

TEST_CASE("Single occurance", "[find_and_replace]")
{
   std::string sentence{"There once was an aardvark that went to market."};
   find_and_replace(sentence, "aardvark", "ostrich");
   REQUIRE(sentence == "There once was an ostrich that went to market.");

   sentence = "Short {a} to long";
   find_and_replace(sentence, "{a}", "this is some really really long text compared to the original");
   REQUIRE(sentence == "Short this is some really really long text compared to the original to long");

   sentence = "Long {this is some really really long text compared to the original} to short";
   find_and_replace(sentence, "{this is some really really long text compared to the original}", "{a}");
   REQUIRE(sentence == "Long {a} to short");
}

TEST_CASE("Not found", "[find_and_replace]")
{
   std::string sentence = "We too the aardvark for a long walk in the desert.";
   find_and_replace(sentence, "ostrich", "blue whale");
   REQUIRE(sentence == "We too the aardvark for a long walk in the desert.");
}

TEST_CASE("Multiple even occurance", "[find_and_replace]")
{
   std::string sentence = "Short {a} to {a} long {a} that was {a}";
   find_and_replace(sentence, "{a}", "[b]");
   REQUIRE(sentence == "Short [b] to [b] long [b] that was [b]");
}

TEST_CASE("Multiple odd occurance", "[find_and_replace]")
{
   std::string sentence = "Short {a} to {a} long that was {a}";
   find_and_replace(sentence, "{a}", "[b]");
   REQUIRE(sentence == "Short [b] to [b] long that was [b]");
}
