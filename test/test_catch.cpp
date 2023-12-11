#define CATCH_CONFIG_MAIN
#include "catch_amalgamated.hpp"
#include "../src/parser.hpp"
#include "../src/localisator.hpp"

SCENARIO("parse and localise mod", "[parser and localisator]")
{
    GIVEN("mod, parser and localisator")
    {
        Parser parser;
        Localisator localisator;
        Mod mod;

        WHEN("parsing mod with incorrect path")
        {
            mod = parser.parse("aboba");

            THEN("locType equals -1")
            {
                REQUIRE(mod.getLocType() == -1);
            }
        }

        WHEN("parsing mod with correct path")
        {
            mod = parser.parse("test\\testMod");

            THEN("mod information is complete")
            {
                REQUIRE(mod.getName() == "test");
                REQUIRE(mod.getImage() == "test\\testMod\\thumbnail.png");
                REQUIRE(mod.getLocType() > 1);
                REQUIRE(mod.getFiles().size() == 3);
            }
        }

        WHEN("localising mod with incorrect path")
        {
            mod = parser.parse("aboba");
            int code = localisator.localise(mod);

            THEN("code equals -1")
            {
                REQUIRE(code == -1);
            }
        }

        WHEN("localising mod with correct path")
        {
            mod = parser.parse("test\\testMod");
            int code = localisator.localise(mod);

            THEN("mod is localised")
            {
                REQUIRE(code == 2);
                REQUIRE(std::filesystem::exists("test\\testMod\\localisation\\test_l_russian.yml"));
                REQUIRE(std::filesystem::exists("test\\testMod\\localisation\\russian\\test_l_russian.yml"));
                REQUIRE(std::filesystem::exists("test\\testMod\\localisation\\russian\\random\\test_l_russian.yml"));
            }
        }
    }
}