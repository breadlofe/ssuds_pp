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
        for(int i = 0; i < 3; i++)
        {
            test_qi.enqueue(i + 2);
            test_qi.enqueue(i - 1);
        }
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
    EXPECT_THROW(test_qf.head(), std::out_of_range);
}

TEST_F(QueueTestFixture, Enqueue1)
{
    test_qi.enqueue(1);
    test_qi.enqueue(7);
    EXPECT_EQ(test_qi.size(), 8);
    EXPECT_EQ(test_qi.head(), 2);
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
    EXPECT_TRUE(test_qf.empty());
}

TEST_F(QueueTestFixture, Empty2)
{
    EXPECT_TRUE(test_qf.empty());
    test_qf.enqueue(3.0f);
    EXPECT_FALSE(test_qf.empty());
}

TEST_F(QueueTestFixture, Empty3)
{
    EXPECT_TRUE(test_qf.empty());
    test_qf.enqueue(3.0f);
    EXPECT_FALSE(test_qf.empty());
    test_qf.dequeue();
    EXPECT_TRUE(test_qf.empty());
}

TEST_F(QueueTestFixture, Iterator1)
{
    ssuds::LinkedList<int>::Iterator test_qi_itr = test_qi.begin();
    EXPECT_EQ(*test_qi_itr, test_qi.head());
    ++test_qi_itr;
    EXPECT_EQ(*test_qi_itr, -1);
}

TEST_F(QueueTestFixture, Iterator2)
{
    ssuds::LinkedList<int>::Iterator test_qi_itr = test_qi.begin();
    EXPECT_EQ(*test_qi_itr, 2);
    test_qi.dequeue();
    EXPECT_EQ(*test_qi_itr, -1);
}

TEST_F(QueueTestFixture, Iterator3)
{
    ssuds::LinkedList<int>::Iterator test_qi_itr = test_qi.end();
    EXPECT_EQ(test_qi_itr.index(), -1);
}

TEST_F(QueueTestFixture, Iterator4)
{
    ssuds::LinkedList<int>::Iterator test_qi_itr = test_qi.begin();
    int combined = 0;
    for(combined; test_qi_itr.index() != -1; ++test_qi_itr)
    {
        combined += *test_qi_itr;
    }
    EXPECT_EQ(combined, 9);
}

TEST_F(QueueTestFixture, Iterator5)
{
    ssuds::LinkedList<int>::Iterator test_qi_itr = test_qi.begin();
    int combined = 0;
    for(combined; test_qi_itr != test_qi.end(); ++test_qi_itr)
    {
        combined += *test_qi_itr;
    }
    EXPECT_EQ(combined, 9);
}

TEST_F(QueueTestFixture, Iterator6)
{
    ssuds::LinkedList<int>::Iterator test_qi_itr = test_qi.begin();
    int combined = 0;
    for(combined; test_qi.size() != 0; test_qi.dequeue())
    {
        combined += *test_qi_itr;
    }
    EXPECT_EQ(combined, 9);
}

TEST_F(QueueTestFixture, OStream1)
{
    testing::internal::CaptureStdout();
    std::cout << test_qs;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "[Patrick]");
}

TEST_F(QueueTestFixture, OStream2)
{
    testing::internal::CaptureStdout();
    std::cout << test_qi;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "[2, -1, 3, 0, 4, 1]");
}

#endif