#include <gtest/gtest.h> 
#include "delimiter_analyzer.h"
#include "queue.h"


#define DELIMETER_TEST 1

#if DELIMETER_TEST
class DelimiterTestFixture : public::testing::Test
{
protected:
    void SetUp() override {
        test_files.enqueue(ssuds::DelimiterAnalyzer("test_files/easy01.lsp"));
        test_files.enqueue(ssuds::DelimiterAnalyzer("test_files/easy02.lsp"));
        test_files.enqueue(ssuds::DelimiterAnalyzer("test_files/easy03.lsp"));
        test_files.enqueue(ssuds::DelimiterAnalyzer("test_files/easy04.lsp"));
        test_files.enqueue(ssuds::DelimiterAnalyzer("test_files/easy05.lsp"));
        test_files.enqueue(ssuds::DelimiterAnalyzer("test_files/easy06.lsp"));
        test_files.enqueue(ssuds::DelimiterAnalyzer("test_files/easy07.lsp"));
    }
    ssuds::Queue<ssuds::DelimiterAnalyzer> test_files;
    ssuds::Queue<ssuds::DelimiterAnalyzer> test_files2;

};

TEST_F(DelimiterTestFixture, Easy)
{
    int i = 0;
    while(!test_files.empty())
    {
        if(i < 4)
            EXPECT_EQ(test_files.head().process(), "All good!\n");
        else
            EXPECT_EQ(test_files.head().process(), "Mismatched tokens. Closing token, but no opening token\n");
        test_files.dequeue();
        i++;
    }
}

TEST_F(DelimiterTestFixture, Medium)
{
    int i = 0;
    while(!test_files.empty())
    {
        if(i < 4)
            EXPECT_EQ(test_files.head().process(), "All good!\n");
        else
            EXPECT_EQ(test_files.head().process(), "Mismatched tokens. Closing token, but no opening token\n");
        test_files.dequeue();
        i++;
    }
}

#endif