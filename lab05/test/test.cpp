#include <gtest/gtest.h>
#include "allocator.hpp"
#include "stack.hpp"
#include <sstream>

TEST(MapTest, MapKeysVal) {
    std::map<int, int, std::less<int>, Allocator<std::pair<const int, int>, 10> > map;
    for (int i = 0; i < 10; ++i) {
        map[i] = i;
    }
    int i = 0;
    for (const auto& p : map) {
        EXPECT_EQ(p.first, i);
        EXPECT_EQ(p.second, i);
        ++i;
    }
}

TEST(StackTest, Empty) {
    Stack<int, Allocator<int, 10> > stack;
    stack.push(2);
    EXPECT_TRUE(!stack.empty());
}

TEST(StackTest, Push) {
    Stack<int, Allocator<int, 10>> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(34);
    stack.pop();

    for (const auto &i : stack) {
        std::cout << i << ' ';
    }
    std::cout << std::endl;
    int i = 3;
    for (const auto& item : stack) {
        EXPECT_EQ(item, i);
        --i;
    }
}

TEST(StackTest, Pop) {
    Stack<int, Allocator<int, 10> > stack;
    for (int i = 1; i <= 5; ++i) {
        stack.push(i);
    }
    stack.pop();
    for (const auto &i : stack) {
        std::cout << i << ' ';
    }
    EXPECT_EQ(stack.size(), 4);
    int i = 4;
    for (const auto& item : stack) {
        EXPECT_EQ(item, i);
        --i;
    }
}/**/

TEST(StackTest, Top) {
    Stack<int, Allocator<int, 6> > stack;
    stack.push(16);
    stack.push(17);
    stack.push(18);
    stack.pop();
    EXPECT_EQ(stack.size(), 2);
    int i = 17;
    for (const auto& item : stack) {
        EXPECT_EQ(item, i);
        --i;
    }   
    EXPECT_EQ(stack.top(), 17);
}

TEST(IteratorTest, Increment) {
    Stack<int, Allocator<int, 10> > stack;
    stack.push(99);
    stack.push(5);
    auto iter = stack.begin();
    EXPECT_EQ(*iter, 5);
    ++iter;
    EXPECT_EQ(*iter, 99);
}

TEST(IteratorTest, EqualityInequality) {
    Stack<int, Allocator<int, 10> > stack;
    stack.push(123);
    auto iter1 = stack.begin();
    auto iter2 = stack.begin();
    EXPECT_TRUE(iter1 == iter2);
    ++iter1;
    EXPECT_TRUE(iter1 != iter2);
}/**/

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}