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

        test_files2.enqueue(ssuds::DelimiterAnalyzer("test_files/medium01.lsp"));
        test_files2.enqueue(ssuds::DelimiterAnalyzer("test_files/medium02.lsp"));
        test_files2.enqueue(ssuds::DelimiterAnalyzer("test_files/medium03.lsp"));
        test_files2.enqueue(ssuds::DelimiterAnalyzer("test_files/medium04.lsp"));
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

// TEST_F(DelimiterTestFixture, Medium)
// {
//     int i = 0;
//     while(!test_files.empty())
//     {
//         if(i == 1 || i == 2)
//             EXPECT_EQ(test_files.head().process(), "All good!\n");
//         else
//             EXPECT_EQ(test_files.head().process(), "Mismatched tokens. Closing token, but no opening token\n");
//         test_files.dequeue();
//         i++;
//     }
// }

TEST_F(DelimiterTestFixture, Medium2)
{
    EXPECT_EQ(test_files2.head().process(), "Mismatched tokens at position: 0, and on line: 2\n");
    test_files2.dequeue();
    EXPECT_EQ(test_files2.head().process(), "All good!\n");
    test_files2.dequeue();
    EXPECT_EQ(test_files2.head().process(), "All good!\n");
    test_files2.dequeue();
    EXPECT_EQ(test_files2.head().process(), "Mismatched tokens at position: 9, and on line: 1\n");
    
}

#endif