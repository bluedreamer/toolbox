#include "catch.hpp"
#include "toolbox.h"

TEST_CASE("Left Trim", "[trim]")
{
   static const std::string expected_result{"test case."};
   std::string              value = "   test case.";
   trim(value);
   REQUIRE(value == expected_result);
   value = "			test case.";
   trim(value);
   REQUIRE(value == expected_result);
   value = "\r\n\rtest case.";
   trim(value);
   REQUIRE(value == expected_result);
   value = "\n\ntest case.";
   trim(value);
   REQUIRE(value == expected_result);
   value = "\r\rtest case.";
   trim(value);
   REQUIRE(value == expected_result);
   value = "  \r   \t\t	\n\r  \r\rtest case.";
   trim(value);
   REQUIRE(value == expected_result);
}

TEST_CASE("Right Trim", "[trim]")
{
   static const std::string expected_result{"test case."};
   std::string              value = "test case.   ";
   trim(value);
   REQUIRE(value == expected_result);
   value = "test case.			";
   trim(value);
   REQUIRE(value == expected_result);
   value = "test case.\r\n\r";
   trim(value);
   REQUIRE(value == expected_result);
   value = "test case.\n\n";
   trim(value);
   REQUIRE(value == expected_result);
   value = "test case.\r\r";
   trim(value);
   REQUIRE(value == expected_result);
   value = "test case.  \r   \t\t	\n\r  \r\r";
   trim(value);
   REQUIRE(value == expected_result);
}

TEST_CASE("Left/Right Trim", "[trim]")
{
   static const std::string expected_result{"test case."};
   std::string              value = "   test case.   ";
   trim(value);
   REQUIRE(value == expected_result);
   value = "		test case.			";
   trim(value);
   REQUIRE(value == expected_result);
   value = "\r\ntest case.\r\n\r";
   trim(value);
   REQUIRE(value == expected_result);
   value = "\n\n\ntest case.\n\n";
   trim(value);
   REQUIRE(value == expected_result);
   value = "\rtest case.\r\r";
   trim(value);
   REQUIRE(value == expected_result);
   value = "  \r\n\n  \t		  \n\rtest case.  \r   \t\t	\n\r  \r\r";
   trim(value);
   REQUIRE(value == expected_result);
}

TEST_CASE("Corner cases", "[trim]")
{
   std::string value = "test case.";
   trim(value);
   REQUIRE(value == std::string{"test case."});
   value = "     ";
   trim(value);
   REQUIRE(value.empty());
   value = "\n\r\n\r";
   trim(value);
   REQUIRE(value.empty());
   value = "";
   trim(value);
   REQUIRE(value.empty());
   value = "			";
   trim(value);
   REQUIRE(value.empty());
}
