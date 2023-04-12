#include <gtest/gtest.h> 
#include "set.h"
#include "arraylist.h"

#define SET_TEST 1

#if SET_TEST

class SetTestFixture : public::testing::Test
{
protected:
    void SetUp() override {
        test_big.add("M");
        test_big.add("G");
        test_big.add("S");
        test_big.add("B");
        test_big.add("A");
        test_big.add("D");
        test_big.add("C");
    }
    ssuds::Set<int> test_si;
    ssuds::Set<float> test_sf;
    ssuds::Set<std::string> test_ss;
    ssuds::Set<std::string> test_big;
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

TEST_F(SetTestFixture, Traversal1)
{
    test_ss.add("Bob");
    test_ss.add("John");
    ssuds::ArrayList<std::string> A;
    A.append("Bob");
    A.append("John");
    EXPECT_EQ(test_ss.traversal(ssuds::TraversalType::PRE)[0], A[0]);
    EXPECT_EQ(test_ss.traversal(ssuds::TraversalType::PRE)[1], A[1]);
}

TEST_F(SetTestFixture, Traversal2)
{
    test_ss.add("Bob");
    test_ss.add("John");
    ssuds::ArrayList<std::string> A;
    A.append("Bob");
    A.append("John");
    EXPECT_EQ(test_ss.traversal(ssuds::TraversalType::POST)[0], A[1]);
    EXPECT_EQ(test_ss.traversal(ssuds::TraversalType::POST)[1], A[0]);
}

TEST_F(SetTestFixture, Traversal3)
{
    test_ss.add("Bob");
    test_ss.add("John");
    test_ss.add("Adam");
    test_ss.add("Carl");
    ssuds::ArrayList<std::string> A;
    A.append("Bob");
    A.append("John");
    A.append("Adam");
    A.append("Carl");
    EXPECT_EQ(test_ss.traversal(ssuds::TraversalType::SORT)[0], A[2]);
    ssuds::quicksort(A,0,A.size()-1,ssuds::sort_type::ASCENDING);
    EXPECT_EQ(test_ss.traversal(ssuds::TraversalType::SORT)[0], A[0]);
    EXPECT_EQ(test_ss.traversal(ssuds::TraversalType::SORT)[3], "John");
}

TEST_F(SetTestFixture, Clear1)
{
    test_sf.add(1.1f);
    test_sf.add(8.9f);
    EXPECT_EQ(test_sf.size(), 2);
    test_sf.clear();
    EXPECT_EQ(test_sf.size(), 0);
}

TEST_F(SetTestFixture, Clear2)
{
    test_sf.add(1.1f);
    test_sf.add(8.9f);
    EXPECT_EQ(test_sf.size(), 2);
    test_sf.clear();
    EXPECT_FALSE(test_sf.contains(1.1f));
}

TEST_F(SetTestFixture, Rebalance1)
{
    test_sf.add(8.0f);
    test_sf.add(7.6f);
    test_sf.add(9.1f);
    test_sf.add(1.1f);
    test_sf.rebalance();
    EXPECT_EQ(test_sf.traversal(ssuds::TraversalType::PRE)[0], 1.1f);
}

TEST_F(SetTestFixture, Erase1)
{
    EXPECT_TRUE(test_big.contains("S"));
    EXPECT_TRUE(test_big.erase("S"));
    EXPECT_FALSE(test_big.contains("S"));
}

TEST_F(SetTestFixture, Erase2)
{
    EXPECT_TRUE(test_big.contains("G"));
    EXPECT_TRUE(test_big.erase("G"));
    EXPECT_FALSE(test_big.contains("G"));
}

TEST_F(SetTestFixture, Erase3)
{
    EXPECT_TRUE(test_big.contains("B"));
    EXPECT_TRUE(test_big.erase("B"));
    EXPECT_FALSE(test_big.contains("B"));
}

TEST_F(SetTestFixture, Erase4)
{
    EXPECT_TRUE(test_big.contains("S"));
    EXPECT_TRUE(test_big.erase("S"));
    EXPECT_FALSE(test_big.contains("S"));
    EXPECT_TRUE(test_big.contains("G"));
}

#endif