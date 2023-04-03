#include <gtest/gtest.h> 
#include "delimiter_analyzer.h"


#define DELIMETER_TEST 1

#if DELIMETER_TEST
class DelimiterTestFixture : public::testing::Test
{
protected:
    void SetUp() override {
        //DelimiterAnalyzer("easy02.lsp") easy2;
    }
    ssuds::DelimiterAnalyzer easy1 = ssuds::DelimiterAnalyzer("test_files/easy01.lsp");
    ssuds::DelimiterAnalyzer easy2 = ssuds::DelimiterAnalyzer("test_files/easy02.lsp");
    ssuds::DelimiterAnalyzer easy3 = ssuds::DelimiterAnalyzer("test_files/easy03.lsp");
    ssuds::DelimiterAnalyzer easy4 = ssuds::DelimiterAnalyzer("test_files/easy04.lsp");
    ssuds::DelimiterAnalyzer easy5 = ssuds::DelimiterAnalyzer("test_files/easy05.lsp");
    ssuds::DelimiterAnalyzer easy6 = ssuds::DelimiterAnalyzer("test_files/easy06.lsp");
    ssuds::DelimiterAnalyzer easy7 = ssuds::DelimiterAnalyzer("test_files/easy07.lsp");

};

TEST_F(DelimiterTestFixture, Easy1)
{
    testing::internal::CaptureStdout();
    std::cout << easy1.process();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(easy1.process(), "All good!\n");
}

TEST_F(DelimiterTestFixture, Easy2)
{
    testing::internal::CaptureStdout();
    std::cout << easy2.process();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(easy1.process(), "All good!\n");
}

TEST_F(DelimiterTestFixture, Easy3)
{
    testing::internal::CaptureStdout();
    std::cout << easy3.process();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(easy1.process(), "All good!\n");
}

TEST_F(DelimiterTestFixture, Easy4)
{
    testing::internal::CaptureStdout();
    std::cout << easy4.process();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(easy1.process(), "All good!\n");
}

TEST_F(DelimiterTestFixture, Easy5)
{
    testing::internal::CaptureStdout();
    std::cout << easy5.process();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(easy1.process(), "All good!\n");
}
#endif