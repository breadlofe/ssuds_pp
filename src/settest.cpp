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

#endif