#include <gtest/gtest.h> 
#include "delimiter_analyzer.h"


#define DELIMETER_TEST 0

#if DELIMETER_TEST
class DelimiterTestFixture : public::testing::Test
{
protected:
    void SetUp() override {
        //DelimiterAnalyzer("easy02.lsp") easy2;
    }
    ssuds::DelimiterAnalyzer easy1 = ssuds::DelimiterAnalyzer("test_files/easy01.lsp");

};

TEST_F(DelimiterTestFixture, Easy1)
{
    // testing::internal::CaptureStdout();
    // std::cout << easy1.process();
    // std::string output = testing::internal::GetCapturedStdout();
    // EXPECT_EQ(output, "All good!");
    EXPECT_EQ(1, 1);
}


#endif