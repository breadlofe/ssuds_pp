#include <gtest/gtest.h> 
#include "queue.h"
#include "linkedlist.h"

#define QUEUE_TEST 1

#if QUEUE_TEST

class QueueTestFixture : public::testing::Test
{
protected:
    void SetUp() override {
        test_qs.enqueue("Patrick");
    }
    ssuds::Queue<int> test_qi;
    ssuds::Queue<float> test_qf;
    ssuds::Queue<std::string> test_qs;
};

TEST_F(QueueTestFixture, Size1)
{
    EXPECT_EQ(test_qs.size(), 1);
}

TEST_F(QueueTestFixture, Head1)
{
    EXPECT_EQ(test_qs.head(), "Patrick");
}

TEST_F(QueueTestFixture, Head2)
{
    EXPECT_THROW(test_qi.head(), std::out_of_range);
}

TEST_F(QueueTestFixture, Enqueue1)
{
    test_qi.enqueue(1);
    test_qi.enqueue(7);
    EXPECT_EQ(test_qi.size(), 2);
    EXPECT_EQ(test_qi.head(), 1);
}

TEST_F(QueueTestFixture, Enqueue2)
{
    test_qf.enqueue(3.1f);
    test_qf.enqueue(35.5f);
    test_qf.enqueue(44.0f);
    EXPECT_EQ(test_qf.size(), 3);
    EXPECT_EQ(test_qf.head(), 3.1f);
}

TEST_F(QueueTestFixture, Dequeue1)
{
    test_qs.dequeue();
    EXPECT_EQ(test_qs.size(), 0);
}

TEST_F(QueueTestFixture, Dequeue2)
{
    test_qs.dequeue();
    EXPECT_EQ(test_qs.size(), 0);
    EXPECT_THROW(test_qs.dequeue(), std::out_of_range);
}

TEST_F(QueueTestFixture, Dequeue3)
{
    test_qs.enqueue("Logan");
    EXPECT_EQ(test_qs.size(), 2);
    test_qs.dequeue();
    EXPECT_EQ(test_qs.head(), "Logan");
}

TEST_F(QueueTestFixture, Clear1)
{
    test_qs.enqueue("Logan");
    EXPECT_EQ(test_qs.size(), 2);
    test_qs.clear();
    EXPECT_EQ(test_qs.size(), 0);
}

TEST_F(QueueTestFixture, Clear2)
{
    test_qi.clear();
    EXPECT_EQ(test_qi.size(), 0);
}

TEST_F(QueueTestFixture, Empty1)
{
    EXPECT_TRUE(test_qi.empty());
}

TEST_F(QueueTestFixture, Empty2)
{
    EXPECT_TRUE(test_qi.empty());
    test_qi.enqueue(3);
    EXPECT_FALSE(test_qi.empty());
}

TEST_F(QueueTestFixture, Empty3)
{
    EXPECT_TRUE(test_qi.empty());
    test_qi.enqueue(3);
    EXPECT_FALSE(test_qi.empty());
    test_qi.dequeue();
    EXPECT_TRUE(test_qi.empty());
}

#endif