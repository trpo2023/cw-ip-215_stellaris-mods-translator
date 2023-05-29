#include "../src/parser.hpp"

#include "../thirdparty/ctest.h"

CTEST(directory_tests, parser_test)
{
    std::vector<paths> outputPathsArray;
    Parser(outputPathsArray, "test/parserTests");
    ASSERT_EQUAL(false, outputPathsArray.empty());
}