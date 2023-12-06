#include <gtest/gtest.h>
#include "../include/Seven.h"

TEST(equal, test_01){
    Seven a{'1'};
    int res = (a == a);
    ASSERT_TRUE(res == 1);
}

TEST(equal, test_02){
    Seven a{'1'};
    Seven b{'0'};
    int res = (a == b);
    ASSERT_TRUE(res == 0);
}

TEST(equal, test_03){
    Seven a{'1'};
    Seven b{'1'};
    int res = (a == b);
    ASSERT_TRUE(res == 1);
}



TEST(assignment, test_01){
    Seven a{'1'};
    Seven b{'0'};
    a = b;
    ASSERT_TRUE(a == b);
}



TEST(not_equal, test01) {
    Seven num1("21"), num2("21");
    ASSERT_FALSE(num1 != num2);
}

TEST(not_equal, test02) {
    Seven num1("23"), num2("1");
    ASSERT_TRUE(num1 != num2);
}

TEST(not_equal, test03) {
    Seven num1("322");
    ASSERT_FALSE(num1 != Seven{"322"});
}

TEST(not_equal, test04) {
    Seven num1("10");
    ASSERT_TRUE(num1 != Seven{"433"});
}



TEST (greater, test01) {
    Seven num1("34"), num2("1");
    ASSERT_TRUE(num1 > num2);
}

TEST(greater, test02) {
    Seven num1("143");
    ASSERT_FALSE(num1 > num1);
}

TEST(greater, test03) {
    Seven num1("22"), num2("12");
    ASSERT_TRUE(num1 > num2);
}

TEST(greater, test04) {
    Seven num1("10"), num2("1220");
    ASSERT_FALSE(num1 > num2);
}

TEST(greater_or_equal, test01) {
    Seven num1("34"), num2("1");
    ASSERT_TRUE(num1 >= num2);
}

TEST(greater_or_equal, test02) {
    Seven num1("144");
    ASSERT_TRUE(num1 >= num1);
}

TEST(greater_or_equal, test03) {
    Seven num1("22"), num2("12");
    ASSERT_TRUE(num1 >= num2);
}

TEST(greater_or_equal, test04) {
    Seven num1("10"), num2("1220");
    ASSERT_FALSE(num1 >= num2);
}



TEST(less, test01) {
    Seven num1("34"), num2("1");
    ASSERT_FALSE(num1 < num2);
}

TEST(less, test02) {
    Seven num1("142");
    ASSERT_FALSE(num1 < num1);
}

TEST(less, test03) {
    Seven num1("22"), num2("12");
    ASSERT_FALSE(num1 < num2);
}

TEST(less, test04) {
    Seven num1("10"), num2("1220");
    ASSERT_TRUE(num1 < num2);
}

TEST(less, test05) {
    Seven num1("10100"), num2("10010");
    ASSERT_FALSE(num1 < num2);
}



TEST(less_or_equal, test01) {
    Seven num1("34"), num2("1");
    ASSERT_FALSE(num1 <= num2);
}

TEST(less_or_equal, test02) {
    Seven num1("144");
    ASSERT_TRUE(num1 <= num1);
}

TEST(less_or_equal, test03) {
    Seven num1("22"), num2("12");
    ASSERT_FALSE(num1 <= num2);
}

TEST(less_or_equal, test04) {
    Seven num1("10"), num2("1220");
    ASSERT_TRUE(num1 <= num2);
}



TEST(add, test01) {
    Seven num1("0"), num2("45");
    ASSERT_TRUE(num1 + num2 == Seven{"45"});
}

TEST(add, test02) {
    Seven num1("76"), num2("0");
    ASSERT_TRUE(num1 + num2 == Seven{"76"});
}

TEST(add, test03) {
    Seven num1("173"), num2("777");
    ASSERT_TRUE(num1 + num2 == Seven{"1172"});
}

TEST(add, test04) {
    Seven num1("77777"), num2("777777");
    ASSERT_TRUE(num1 + num2 == Seven{"1077776"});
}

TEST(add, test05) {
    Seven num1("56541"), num2("103");
    ASSERT_TRUE(num1 + num2 == Seven{"56644"});
}



TEST(sub, test01) {
    Seven num1("15"), num2("10");
    ASSERT_TRUE(num1 - num2 == Seven{'5'});
}

TEST(sub, test02) {
    Seven num1("7"), num2("1");
    ASSERT_TRUE(num1 - num2 == Seven{'6'});
}

TEST(sub, test03) {
    Seven num1("10"), num2("3");
    ASSERT_TRUE(num1 - num2 == Seven{'5'});
}

TEST(sub, test04) {
    Seven num1("27232"), num2("27232");
    ASSERT_TRUE(num1 - num2 == Seven{'0'});
}

TEST(sub, test05) {
    Seven num1("7777700000077777111"), num2("7777777777777777");
    ASSERT_TRUE(num1 - num2 == Seven{"7767700000077777112"});
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}