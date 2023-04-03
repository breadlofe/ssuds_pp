#include <gtest/gtest.h> 
#include "stack.h"
#include "linkedlist.h"

#define STACK_TEST 0

#if STACK_TEST

class StackTestFixture : public::testing::Test
{
protected:
    void SetUp() override {
        test_qs.push("Patrick");
        for(int i = 0; i < 3; i++)
        {
            test_qi.push(i + 2);
            test_qi.push(i - 1);
        }
    }
    ssuds::Stack<int> test_qi;
    ssuds::Stack<float> test_qf;
    ssuds::Stack<std::string> test_qs;
};

TEST_F(StackTestFixture, Push1)
{
    test_qf.push(1.1f);
    EXPECT_EQ(test_qf.size(), 1);
}

TEST_F(StackTestFixture, Push2)
{
    EXPECT_EQ(test_qi.size(), 6);
}

TEST_F(StackTestFixture, Get1)
{
    EXPECT_EQ(test_qi.get(0), 1);
}

TEST_F(StackTestFixture, Pop1)
{
    EXPECT_EQ(test_qi.pop(), 1);
}

TEST_F(StackTestFixture, Pop2)
{
    EXPECT_EQ(test_qi.pop(), 1);
    EXPECT_EQ(test_qi.pop(), 4);
    EXPECT_EQ(test_qi.pop(), 0);
    EXPECT_EQ(test_qi.pop(), 3);
    EXPECT_EQ(test_qi.pop(), -1);
    EXPECT_EQ(test_qi.pop(), 2);
    EXPECT_EQ(test_qi.size(), 0);
}

TEST_F(StackTestFixture, Top1)
{
    test_qs.push("Logan");
    EXPECT_EQ(test_qs.top(), "Logan");
}

TEST_F(StackTestFixture, Top2)
{
    test_qs.push("Logan");
    EXPECT_EQ(test_qs.top(), "Logan");
    test_qs.pop();
    EXPECT_EQ(test_qs.top(), "Patrick");
}

TEST_F(StackTestFixture, Clear1)
{
    test_qi.clear();
    EXPECT_EQ(test_qi.size(), 0);
}

TEST_F(StackTestFixture, Empty1)
{
    test_qs.push("Logan");
    EXPECT_FALSE(test_qs.empty());
    test_qs.clear();
    EXPECT_TRUE(test_qs.empty());
}

TEST_F(StackTestFixture, OStream1)
{
    testing::internal::CaptureStdout();
    std::cout << test_qi;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "[1, 4, 0, 3, -1, 2]");
}

TEST_F(StackTestFixture, Iterator1)
{
    ssuds::LinkedList<int>::Iterator test_qi_itr = test_qi.begin();
    EXPECT_EQ(*test_qi_itr, test_qi.top());
}

TEST_F(StackTestFixture, Iterator2)
{
    ssuds::LinkedList<int>::Iterator test_qi_itr = test_qi.begin();
    EXPECT_EQ(*test_qi_itr, test_qi.top());
    ++test_qi_itr;
    EXPECT_EQ(*test_qi_itr, 4);
}

TEST_F(StackTestFixture, Iterator3)
{
    ssuds::LinkedList<int>::Iterator test_qi_itr = test_qi.begin();
    test_qi.pop();
    EXPECT_EQ(*test_qi_itr, 4);
}

#endif