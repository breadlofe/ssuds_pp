#include <gtest/gtest.h> 
#include "arraylist.h"
#include "arraylist_utility.h"
#include "linkedlist.h"

#define LINKED_LIST_TEST 0

#if LINKED_LIST_TEST

class LinkedTestFixture : public::testing::Test
{
protected:
    void SetUp() override {
        test_ls.append("Patrick");
    }

    ssuds::LinkedList<int> test_li;
    ssuds::LinkedList<float> test_lf;
    ssuds::LinkedList<std::string> test_ls;
    ssuds::LinkedList<int>::Iterator test_it_li;
};

//** LINKED LIST TESTS **//
TEST_F(LinkedTestFixture, Append1)
{
    test_li.append(1);
    EXPECT_EQ(test_li.size(), 1);
}

TEST_F(LinkedTestFixture, Append2)
{
    test_lf.append(1.0f);
    EXPECT_EQ(test_lf.size(), 1);
}

TEST_F(LinkedTestFixture, Append3)
{
    test_ls.append("Bob");
    EXPECT_EQ(test_ls.size(), 2);
}

TEST_F(LinkedTestFixture, Append4)
{
    test_li.append(1);
    test_li.append(2);
    EXPECT_EQ(test_li.size(), 2);
}

TEST_F(LinkedTestFixture, Prepend1)
{
    test_li.prepend(1);
    EXPECT_EQ(test_li.size(), 1);
}

TEST_F(LinkedTestFixture, AppendandPrepend1)
{
    test_li.append(1);
    test_li.prepend(3);
    EXPECT_EQ(test_li.size(), 2);
}

TEST_F(LinkedTestFixture, BracketOP1)
{
    test_li.append(1);
    EXPECT_EQ(test_li[0],1);
}

TEST_F(LinkedTestFixture, BracketOP2)
{
    test_li.append(1);
    test_li.prepend(3);
    EXPECT_EQ(test_li[0],3);
}

TEST_F(LinkedTestFixture, BracketOP3)
{
    test_li.append(1);
    test_li.prepend(3);
    EXPECT_EQ(test_li[1],1);
}

TEST_F(LinkedTestFixture, OStream1)
{
    test_li.append(4);
    test_li.append(2);
    testing::internal::CaptureStdout();
    std::cout << test_li;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "[4, 2]");
}

TEST_F(LinkedTestFixture, LinkedItr1)
{
    test_li.append(4);
    test_li.append(2);
    test_it_li = test_li.begin();
    EXPECT_EQ(test_it_li.index(), 0);
}

TEST_F(LinkedTestFixture, LinkedItr2)
{
    test_li.append(4);
    test_li.append(2);
    test_it_li = test_li.begin();
    ++test_it_li;
    EXPECT_EQ(test_it_li.index(), 1);
}

TEST_F(LinkedTestFixture, LinkedItr3)
{
    test_li.append(4);
    test_li.append(2);
    test_it_li = test_li.begin();
    ++test_it_li;
    EXPECT_EQ(*test_it_li, 2);
}

TEST_F(LinkedTestFixture, LinkedItr4)
{
    test_li.append(4);
    test_li.append(2);
    test_it_li = test_li.begin();
    EXPECT_TRUE(test_li.find(4) == test_it_li);
}

#endif