#include <gtest/gtest.h>
#include "func.h"

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(func("Понедельник",12)==1);
}

TEST(test_02, basic_test_set)
{
    ASSERT_TRUE(func("Понедельник",35)==0);
}

TEST(test_03, basic_test_set)
{
    ASSERT_TRUE(func("Вторник",96)==1);
}

TEST(test_04, basic_test_set)
{
    ASSERT_TRUE(func("Вторник",95)==0);
}

TEST(test_05, basic_test_set)
{
    ASSERT_TRUE(func("Среда",34)==1);
}

TEST(test_06, basic_test_set)
{
    ASSERT_TRUE(func("Среда",25)==0);
}

TEST(test_07, basic_test_set)
{
    ASSERT_TRUE(func("Четверг",0)==1);
}

TEST(test_08, basic_test_set)
{
    ASSERT_TRUE(func("Четверг",87)==0);
}

TEST(test_09, basic_test_set)
{
    ASSERT_TRUE(func("Пятница",438)==1);
}

TEST(test_10, basic_test_set)
{
    ASSERT_TRUE(func("Пятница",439)==0);
}

TEST(test_11, basic_test_set)
{
    ASSERT_TRUE(func("Суббота",56)==1);
}

TEST(test_12, basic_test_set)
{
    ASSERT_TRUE(func("Суббота",687)==0);
}

TEST(test_13, basic_test_set)
{
    ASSERT_TRUE(func("Воскресенье",666)==1);
}

TEST(test_14, basic_test_set)
{
    ASSERT_TRUE(func("Воскресенье",-666)==1);
}

TEST(test_15, basic_test_set)
{
    ASSERT_TRUE(func("Воскресенье",456)==0);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}