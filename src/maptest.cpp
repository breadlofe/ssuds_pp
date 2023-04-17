#include <gtest/gtest.h> 
#include "unorderedmap.h"

#define MAP_TEST 1

#if MAP_TEST

class MapTestFixture : public::testing::Test
{
protected:
    void SetUp() override {
        test_map["Alice"] = 1;
    }
    ssuds::UnorderedMap<std::string,int> test_map;
};

TEST_F(MapTestFixture, BracketOP1)
{
    ssuds::UnorderedMap<std::string,int> test_map_here;
    test_map_here["Bob"] = 2;
}

TEST_F(MapTestFixture, BracktOP2)
{
    EXPECT_EQ(test_map["Alice"], 1);
}

#endif