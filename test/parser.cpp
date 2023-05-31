#include "../src/parser.hpp"

#include "../thirdparty/ctest.h"

CTEST(parser_test, vector_fill)
{
    std::vector<paths> outputPathsArray;
    Parser(outputPathsArray, "test/parserTests");
    ASSERT_EQUAL(4, outputPathsArray.size());
}

CTEST(translate_path, raw_location)
{
    std::string raw_location = translatePath("test/parserTests/test_l_english.yml");
    ASSERT_STR("test/parserTests/test_l_russian.yml", raw_location.c_str());
}

CTEST(translate_path, language_directory)
{
    std::string language_directory = translatePath("test/parserTests/english/test_l_english.yml");
    ASSERT_STR("test/parserTests/russian/test_l_russian.yml", language_directory.c_str());
}

CTEST(translate_path, replace_directory)
{
    std::string replace_directory = translatePath("test/parserTests/replace/test_l_english.yml");
    ASSERT_STR("test/parserTests/replace/test_l_russian.yml", replace_directory.c_str());
}

CTEST(translate_path, replace_language_directory)
{
    std::string replace_language_directory = translatePath("test/parserTests/replace/english/test_l_english.yml");
    ASSERT_STR("test/parserTests/replace/russian/test_l_russian.yml", replace_language_directory.c_str());
}