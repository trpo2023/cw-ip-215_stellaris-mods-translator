#include "../src/log.hpp"

#include "../thirdparty/ctest.h"

CTEST(one_turn_tests, log_test)
{
    int N = 6; // кол-во вариантов выхода
    std::string result[N];

    std::string expected[] =
    {
        "file is succesfully translated\n",
        "file is succesfully transfered\n",
        "file is automatically translated before\n",
        "file is translated by mod autor\n",
        "file already exists\n",
        "invalid working type\n"
    };

    for(int i = 0; i < N; i += 1)
        ASSERT_STR(expected[i].c_str(), log(i).c_str());
}