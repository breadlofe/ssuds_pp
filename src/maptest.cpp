#include <gtest/gtest.h> 
#include "unorderedmap.h"

#define MAP_TEST 1

#if MAP_TEST

class MapTestFixture : public::testing::Test
{
protected:
    void SetUp() override {
        test_map["Alice"] = 1;
        for(int i = 0; i < 8; i++)
        {
            test_big_map[i] = i;
        }
    }
    ssuds::UnorderedMap<std::string,int> test_map;
    ssuds::UnorderedMap<int,int> test_big_map;
};

TEST_F(MapTestFixture, BracketOP1)
{
    ssuds::UnorderedMap<float,unsigned int> test_map_local;
    test_map_local[1.1f] = 2;
}

TEST_F(MapTestFixture, BracktOP2)
{
    EXPECT_EQ(test_map["Alice"], 1);
}

TEST_F(MapTestFixture, BracktOP3)
{
    test_map["Bill"] = 2;
    test_map["Carl"] = 3;
    EXPECT_EQ(test_map["Carl"], 3);
}

TEST_F(MapTestFixture, Size1)
{
    test_map["Bill"] = 2;
    test_map["Carl"] = 3;
    EXPECT_EQ(test_map.size(), 3);
}

TEST_F(MapTestFixture, Size2)
{
    ssuds::UnorderedMap<float,unsigned int> test_map_local;
    EXPECT_EQ(test_map_local.size(), 0);
}

TEST_F(MapTestFixture, Capacity1)
{
    EXPECT_EQ(test_map.capacity(), 10);
}

TEST_F(MapTestFixture, Capacity2)
{
    EXPECT_EQ(test_big_map.capacity(), 20);
}

TEST_F(MapTestFixture, Capacity3)
{
    EXPECT_EQ(test_big_map.size(), 8);
    EXPECT_EQ(test_big_map[0], 0);
}

#endif