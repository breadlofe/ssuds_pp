#include <gtest/gtest.h> 
#include "set.h"

#define SET_TEST 1

#if SET_TEST

class SetTestFixture : public::testing::Test
{
protected:
    void SetUp() override {
    }
    ssuds::Set<int> test_si;
    ssuds::Set<float> test_sf;
    ssuds::Set<std::string> test_ss;
};

TEST_F(SetTestFixture, Size1)
{
    EXPECT_EQ(test_ss.size(), 0);
}

TEST_F(SetTestFixture, Add1)
{
    EXPECT_TRUE(test_si.add(1));
}

TEST_F(SetTestFixture, Add2)
{
    EXPECT_TRUE(test_ss.add("Bob"));
    EXPECT_TRUE(test_ss.add("John"));
    EXPECT_EQ(test_ss.size(), 2);
}

TEST_F(SetTestFixture, Contains1)
{
    test_ss.add("Bob");
    test_ss.add("John");
    EXPECT_TRUE(test_ss.contains("Bob"));
}

TEST_F(SetTestFixture, Contains2)
{
    test_ss.add("Bob");
    test_ss.add("John");
    EXPECT_FALSE(test_ss.contains("Bill"));
}

TEST_F(SetTestFixture, Height1)
{
    test_ss.add("Bob");
    test_ss.add("John");
    EXPECT_EQ(test_ss.get_height(), 2);
}

#endif