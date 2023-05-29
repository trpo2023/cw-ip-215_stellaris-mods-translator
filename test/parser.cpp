#include <parser.hpp>

#include <thirdparty/ctest.h>

CTEST(directory_tests, parser_test)
{
    std::vector<paths> outputPathsArray;
    std::filesystem::copy("pathForTest", "pathForTestCopy");
    Parser(outputPathsArray, "pathForTestCopy");

    ASSERT_EQUAL(false, outputPathsArray.empty());
}