#include <gtest/gtest.h> 
#include "unorderedmap.h"

#define MAP_TEST 0

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

TEST_F(MapTestFixture, OStream1)
{
    testing::internal::CaptureStdout();
    std::cout << test_map;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "{Alice:1}");
}

TEST_F(MapTestFixture, OStream2)
{
    testing::internal::CaptureStdout();
    std::cout << test_big_map;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "{0:0, 1:1, 2:2, 3:3, 4:4, 5:5, 6:6, 7:7}");
}

TEST_F(MapTestFixture, Contains1)
{
    EXPECT_TRUE(test_map.contains("Alice"));
    EXPECT_FALSE(test_map.contains("Carl"));
}

TEST_F(MapTestFixture, Remove1)
{
    test_map.remove("Alice");
    EXPECT_FALSE(test_map.contains("Alice"));
    EXPECT_EQ(test_map.size(), 0);
}

TEST_F(MapTestFixture, Remove2)
{
    test_big_map.remove(2);
    testing::internal::CaptureStdout();
    std::cout << test_big_map;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "{0:0, 1:1, 3:3, 4:4, 5:5, 6:6, 7:7}");
}

TEST_F(MapTestFixture, Itr1)
{
    ssuds::UnorderedMap<std::string, int>::UnorderedMapIterator test_local_itr;
    test_local_itr = test_map.begin();
}

TEST_F(MapTestFixture, Itr2)
{
    ssuds::UnorderedMap<std::string, int>::UnorderedMapIterator test_local_itr;
    test_local_itr = test_map.begin();
    EXPECT_EQ((*test_local_itr), "Alice");
}

TEST_F(MapTestFixture, Itr3)
{
    test_map["Jill"] = 5;
    ssuds::UnorderedMap<std::string, int>::UnorderedMapIterator test_local_itr;
    test_local_itr = test_map.begin();
    ++test_local_itr;
    EXPECT_EQ((*test_local_itr), "Jill");
}

TEST_F(MapTestFixture, Itr4)
{
    test_map["Jill"] = 5;
    ssuds::UnorderedMap<std::string, int>::UnorderedMapIterator test_local_itr;
    ssuds::UnorderedMap<std::string, int>::UnorderedMapIterator test_local_itr_copy;
    test_local_itr = test_map.begin();
    test_local_itr_copy = test_map.begin();
    EXPECT_TRUE(test_local_itr == test_local_itr_copy);
    EXPECT_FALSE(test_local_itr != test_local_itr_copy);
}

TEST_F(MapTestFixture, Itr5)
{
    test_map["Jill"] = 5;
    ssuds::UnorderedMap<std::string, int>::UnorderedMapIterator test_local_itr;
    ssuds::UnorderedMap<std::string, int>::UnorderedMapIterator test_local_itr_copy;
    test_local_itr = test_map.begin();
    test_local_itr_copy = test_map.begin();
    ++test_local_itr;
    EXPECT_FALSE(test_local_itr == test_local_itr_copy);
    EXPECT_TRUE(test_local_itr != test_local_itr_copy);
}

#endif