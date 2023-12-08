#include "../src/fileLocalise.hpp"

#include "../thirdparty/ctest.h"

CTEST(localise_tests, file_retranslate)
{
    paths retranslate_test = {"test/localiseTests/test_l_english.yml", "test/localiseTests/auto_l_russian.yml"};
    ASSERT_EQUAL(SUCCESFULLY_TRANSLATED, localise(retranslate_test, "0", 2));
}

CTEST(localise_tests, file_fill)
{
    paths fill_test = {"test/localiseTests/test_l_english.yml", "test/localiseTests/test_l_russian.yml"};
    ASSERT_EQUAL(SUCCESFULLY_CREATED, localise(fill_test, "0", 0));
}

CTEST(localise_tests, auto_file)
{
    paths auto_test = {"test/localiseTests/test_l_english.yml", "test/localiseTests/auto_l_russian.yml"};
    ASSERT_EQUAL(FILE_ALREADY_TRANSLATED, localise(auto_test, "0", 1));
}

CTEST(localise_tests, autor_file)
{
    paths autor_test = {"test/localiseTests/test_l_english.yml", "test/localiseTests/autor_l_russian.yml"};
    ASSERT_EQUAL(FILE_TRANSLATED_BY_MOD_CREATOR, localise(autor_test, "0", 1));
}

CTEST(localise_tests, file_exists)
{
    paths exist_test = {"test/localiseTests/test_l_english.yml", "test/localiseTests/autor_l_russian.yml"};
    ASSERT_EQUAL(FILE_EXIST, localise(exist_test, "0", 0));
}