#include <parser.hpp>

#include <ctest.h>

CTEST(directory_tests, parser_test)
{
    std::vector<paths> outputPathsArray;
    std::filesystem::copy("pathForTest", "pathForTestCopy");
    Parser(pathsArray, "pathForTestCopy");

    ASSERT_EQUAL(false, outputPathsArray.empty());
}