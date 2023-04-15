#include <gtest/gtest.h> 
#include "unorderedmap.h"

#define MAP_TEST 1

#if MAP_TEST

class MapTestFixture : public::testing::Test
{
protected:
    void SetUp() override {
    }

};

TEST_F(MapTestFixture, BracketOP1)
{
    ssuds::UnorderedMap<std::string,int> test_map;
    test_map["Bob"] = 2;

    //test_map[1] = 1;
}

#endif