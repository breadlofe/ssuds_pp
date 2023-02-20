#include <gtest/gtest.h> 
#include "arraylist.h"
#include "arraylist_utility.h"

class TestFixture : public::testing::Test
{
protected:
    void SetUp() override {
        test_f.append(0.1f);
        test_i.append(1);
        test_s.append("Patrick");
    }

    ssuds::ArrayList<float> test_f;
    ssuds::ArrayList<int> test_i;
    ssuds::ArrayList<std::string> test_s;
    ssuds::ArrayList<std::string> test_sf;
    ssuds::ArrayList<int>::Iterator test_it_i;
};

TEST(Sample, SampleTest)
{
    EXPECT_EQ(42, 42);
}

TEST_F(TestFixture, Template1)
{
    EXPECT_NE(typeid(test_f[0]), typeid(test_i[0]));
}

TEST_F(TestFixture, Append1)
{
    test_f.append(1.0f);
    test_f.append(3.3f);
    EXPECT_EQ(test_f.size(), 3);
}

TEST_F(TestFixture, Capacity1)
{
    EXPECT_EQ(test_i.get_capacity(), 5);
}

TEST_F(TestFixture, Capacity2)
{
    for(int i = 0; i < 9; i++)
    {
        test_i.append(i+rand()%10);
    }
    EXPECT_EQ(test_i.get_capacity(), 10);
    test_i.append(4);
    EXPECT_EQ(test_i.get_capacity(), 20);
}

TEST_F(TestFixture, Capacity3)
{
    for(int i = 0; i < 9; i++)
    {
        test_i.append(i+rand()%10);
    }
    EXPECT_EQ(test_i.get_capacity(), 10);
    test_i.append(4);
    EXPECT_EQ(test_i.get_capacity(), 20);
    test_i.remove(0);                       // NOTE: Capacity shrinks once size has
    EXPECT_EQ(test_i.size(), 10);           // gone BELOW set capcity level.
    test_i.remove(0);                       // This is because mSize-- occurs at
    EXPECT_EQ(test_i.get_capacity(), 10);   // the end of the function.
}


TEST_F(TestFixture, Remove1)
{
    test_s.remove(0);
    EXPECT_EQ(test_s.size(), 0);
}

TEST_F(TestFixture, Remove2)
{
    EXPECT_THROW(test_s.remove(1), std::out_of_range);
}

TEST_F(TestFixture, Remove_All1)
{
    for(int i = 0; i < 20; i++)
    {
        test_s.append("virus!");
    }
    EXPECT_EQ(test_s.size(), 21);
    test_s.remove_all("virus!");
    EXPECT_EQ(test_s.size(), 1);
}

TEST_F(TestFixture, Remove_All2)
{
    for(int i = 0; i < 5; i++)
    {
        test_s.append("good_program");
        test_s.append("maleware_tag");
    }
    EXPECT_EQ(test_s.size(), 11);
    test_s.remove_all("maleware_tag");
    EXPECT_EQ(test_s.size(), 6);
}

TEST_F(TestFixture, Remove_All3)
{
    test_s.append("single_install_program");
    test_s.append("only_need_one");
    for(int i = 0; i < 5; i++)
    {
        test_s.append("dup_virus!");
        test_s.append("single_install_program");
    }
    EXPECT_EQ(test_s.size(), 13);
    test_s.remove_all("dup_virus!");
    EXPECT_EQ(test_s.size(), 8);
    test_s.remove_all("single_install_program", 2);
    EXPECT_EQ(test_s.size(), 3);
    EXPECT_EQ(test_s.get(1), "single_install_program");

}

TEST_F(TestFixture, Get1)
{
    EXPECT_EQ(test_s.get(0), "Patrick");
    EXPECT_EQ(test_i.get(0), 1);
    EXPECT_EQ(test_f.get(0), 0.1f);
}

TEST_F(TestFixture, Get2)
{
    EXPECT_THROW(test_f.get(1), std::out_of_range);
}

TEST_F(TestFixture, Copy1)
{
    ssuds::ArrayList<int> test_copy;
    test_copy = test_i;
    test_i.append(33);
    test_copy.append(12);
    EXPECT_EQ(test_i.size(), test_copy.size());
    EXPECT_NE(test_i.get(1), test_copy.get(1));
}

TEST_F(TestFixture, Copy2)
{
    ssuds::ArrayList<int> test_copy;
    for(int i = 0; i < 10; i++)
    {
        test_i.append(rand()%10);
    }
    test_copy = test_i;
    EXPECT_EQ(test_copy.get(3), test_i.get(3));
    EXPECT_EQ(test_copy.get_capacity(), test_i.get_capacity());
}

TEST_F(TestFixture, Copy3)
{
    ssuds::ArrayList<int> test_copy;
    for(int i = 0; i < 10; i++)
    {
        test_i.append(rand()%10);
    }
    test_copy = test_i;
    // Already know it's copied through Copy2 test.
    for(int i = 0; i < 10; i++)
    {
        test_i.remove(0);
    }
    // Already know that capacity has shrunk correctly from Capacity3 test.
    EXPECT_NE(test_i.get_capacity(), test_copy.get_capacity());
}

TEST_F(TestFixture, Bracket_OP1)
{
    EXPECT_EQ(test_s[0], test_s.get(0));
    // Already know that get returns item at index from Get1 test.
}

TEST_F(TestFixture, Bracket_OP2)
{
    EXPECT_THROW(test_f[1], std::out_of_range);
}

TEST_F(TestFixture, Insert1)
{
    test_f.insert(8.1f, 0);
    EXPECT_EQ(test_f[0], 8.1f);
}

TEST_F(TestFixture, Insert2)
{
    for(int i = 0; i < 9; i++)
    {
        test_f.append((rand()%10)/9.0f * 10.0f);    // Random float between 0.0 and 10.0
    }
    EXPECT_EQ(test_f.get_capacity(), 10);
    test_f.insert(11.3f, 5);
    // Already know that insert succesfully places item at index due to Insert1 test.
    EXPECT_EQ(test_f.get_capacity(), 20);
}

TEST_F(TestFixture, Insert3)
{
    for(int i = 0; i < 9; i++)
    {
        test_f.append((rand()%10)/9.0f * 10.0f);    // Random float between 0.0 and 10.0
    }
    EXPECT_EQ(test_f.size(), 10);
    test_f.insert(11.3f, 5);
    // Already know that insert succesfully places item at index due to Insert1 test.
    EXPECT_EQ(test_f.size(), 11);
}

TEST_F(TestFixture, Insert4)
{
    for(int i = 0; i < 9; i++)
    {
        test_f.append((rand()%10)/9.0f * 10.0f);    // Random float between 0.0 and 10.0
    }
    EXPECT_EQ(test_f.get_capacity(), 10);
    test_f.insert(11.3f, 5);
    // Already know that insert succesfully places item at index from Insert1 test.
    EXPECT_EQ(test_f[5], 11.3f);
    // Already know that bracket succesfully gets item at index from Bracket_OP1 test.
}

TEST_F(TestFixture, OStream1)
{
    test_s.append("Chris");
    test_s.append("Logan");
    testing::internal::CaptureStdout();
    std::cout << test_s;
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "[Patrick, Chris, Logan]");
}

TEST_F(TestFixture, Clear1)
{
    test_f.clear();
    EXPECT_EQ(test_f.size(), 0);
}

TEST_F(TestFixture, Clear2)
{
    for(int i = 0; i < 10; i++)
    {
        test_i.append(rand()%10);
    }
    // Already know that capacity increases correctly from Capacity2 test.
    test_i.clear();
    EXPECT_EQ(test_i.get_capacity(), 5);
}

TEST_F(TestFixture, Find1)
{
    EXPECT_EQ(test_s.find("Patrick"), 0);
}

TEST_F(TestFixture, Find2)
{
    EXPECT_THROW(test_s.find("Patrick", 1), std::out_of_range);
}

TEST_F(TestFixture, Find3)
{
    EXPECT_EQ(test_s.find("patrick"), -1);
}

TEST_F(TestFixture, Find4)
{
    test_s.append("Logan");
    test_s.append("Logan");
    test_s.append("Chris");
    test_s.append("Logan");
    EXPECT_EQ(test_s.find("Logan", 3), 4);
}

TEST_F(TestFixture, Iterator1)
{
    test_it_i = test_i.begin();
    EXPECT_EQ(*test_it_i, 1);
}

TEST_F(TestFixture, Iterator2)
{
    test_i.append(5);
    test_it_i = test_i.begin();
    ++test_it_i;
    EXPECT_EQ(*test_it_i, 5);
}

TEST_F(TestFixture, Iterator3)
{
    int ran = 0;
    while(test_it_i != test_i.end())
    {
        ++test_it_i;
        ran++;
    }
    EXPECT_EQ(ran, 1);
}

TEST_F(TestFixture, Iterator4)
{
    int ran = 0;
    test_i.append(4);
    test_i.append(6);
    test_it_i = test_i.begin();
    while(test_it_i != test_i.end())
    {
        ++test_it_i;
        ran++;
    }
    EXPECT_EQ(ran, 3);
}

TEST_F(TestFixture, IteratorEQ)
{
    test_i.append(6);
    ssuds::ArrayList<int> test_i_copy;
    test_i_copy = test_i;
    test_it_i = test_i.begin();
    ssuds::ArrayList<int>::Iterator test_it_i_copy;
    test_it_i_copy = test_i_copy.begin();
    EXPECT_TRUE(test_it_i == test_it_i_copy);
}

TEST_F(TestFixture, IteratorEQ2)
{
    test_i.append(6);
    ssuds::ArrayList<int> test_i_copy;
    test_i_copy.append(1);
    test_it_i = test_i.begin();
    ssuds::ArrayList<int>::Iterator test_it_i_copy;
    test_it_i_copy = test_i_copy.begin();
    EXPECT_FALSE(test_it_i == test_it_i_copy);
}

TEST_F(TestFixture, IteratorEQ3)
{
    test_i.append(6);
    ssuds::ArrayList<int> test_i_copy;
    test_i_copy.append(1);
    test_i_copy.append(5);
    test_it_i = test_i.begin();
    ssuds::ArrayList<int>::Iterator test_it_i_copy;
    test_it_i_copy = test_i_copy.begin();
    EXPECT_FALSE(test_it_i == test_it_i_copy);
}

TEST_F(TestFixture, IteratorEQ4)
{
    test_i.append(6);
    ssuds::ArrayList<int> test_i_copy;
    test_i_copy.append(1);
    test_i_copy.append(6);
    test_it_i = test_i.begin();
    ssuds::ArrayList<int>::Iterator test_it_i_copy;
    test_it_i_copy = test_i_copy.begin();
    ++test_it_i_copy;
    EXPECT_FALSE(test_it_i == test_it_i_copy);
}

TEST_F(TestFixture, IteratorNEQ)
{
    test_i.append(6);
    ssuds::ArrayList<int> test_i_copy;
    test_i_copy = test_i;
    test_it_i = test_i.begin();
    ssuds::ArrayList<int>::Iterator test_it_i_copy;
    test_it_i_copy = test_i_copy.begin();
    EXPECT_FALSE(test_it_i != test_it_i_copy);
}

TEST_F(TestFixture, IteratorNEQ2)
{
    test_i.append(6);
    ssuds::ArrayList<int> test_i_copy;
    test_i_copy.append(1);
    test_it_i = test_i.begin();
    ssuds::ArrayList<int>::Iterator test_it_i_copy;
    test_it_i_copy = test_i_copy.begin();
    EXPECT_TRUE(test_it_i != test_it_i_copy);
}

TEST_F(TestFixture, IteratorNEQ3)
{
    test_i.append(6);
    ssuds::ArrayList<int> test_i_copy;
    test_i_copy.append(1);
    test_i_copy.append(5);
    test_it_i = test_i.begin();
    ssuds::ArrayList<int>::Iterator test_it_i_copy;
    test_it_i_copy = test_i_copy.begin();
    EXPECT_TRUE(test_it_i != test_it_i_copy);
}

TEST_F(TestFixture, IteratorNEQ4)
{
    test_i.append(6);
    ssuds::ArrayList<int> test_i_copy;
    test_i_copy.append(1);
    test_i_copy.append(6);
    test_it_i = test_i.begin();
    ssuds::ArrayList<int>::Iterator test_it_i_copy;
    test_it_i_copy = test_i_copy.begin();
    ++test_it_i_copy;
    EXPECT_TRUE(test_it_i != test_it_i_copy);
}

TEST_F(TestFixture, InitializerList1)
{
    ssuds::ArrayList<int> int_list = {1,4,5,7};
    EXPECT_EQ(int_list[3], 7);
}

TEST_F(TestFixture, InitializerList2)
{
    ssuds::ArrayList<int> int_list = {1,4,5,7};
    ssuds::ArrayList<int> list_copy;
    list_copy = int_list;
    EXPECT_EQ(list_copy[3], 7);
}

TEST_F(TestFixture, Shuffle1)
{
    ssuds::ArrayList<int> int_list = {1,7,9,11,12,15};
    ssuds::ArrayList<int> list_copy; 
    list_copy = int_list;
    ssuds::shuffle(int_list);
    unsigned int different = 0;

    for(int i = 0; i < int_list.size(); i++)
    {
        if(int_list[i] != list_copy[i])
            different++;
    }
    
    EXPECT_GT(different, 0);
}

TEST_F(TestFixture, BubbleSort1)
{
    ssuds::ArrayList<int> int_list = {1, 2, 5, 3};
    ssuds::bubble_sort(int_list, ssuds::sort_type::ASCENDING);
    EXPECT_EQ(int_list[3], 5);
}

TEST_F(TestFixture, BubbleSort2)
{
    ssuds::ArrayList<int> int_list = {1, 2, 5, 3};
    EXPECT_EQ(ssuds::bubble_sort(int_list, ssuds::sort_type::ASCENDING), 1);
}

TEST_F(TestFixture, BubbleSort3)
{
    ssuds::ArrayList<int> int_list = {1, 2, 5, 3};
    EXPECT_EQ(ssuds::bubble_sort(int_list, ssuds::sort_type::DESCENDING), 5);
}

TEST_F(TestFixture, BinarySearch1)
{
    ssuds::ArrayList<int> int_list = {1, 2, 3, 5, 7, 9};
    EXPECT_EQ(ssuds::binary_search(int_list, 7, ssuds::sort_type::ASCENDING), 4);
}

TEST_F(TestFixture, BinarySearch2)
{
    ssuds::ArrayList<int> int_list = {1, 2, 3, 5, 7, 9};
    long int comparison_cntr[] = {0};
    ssuds::binary_search(int_list, 7, ssuds::sort_type::ASCENDING, comparison_cntr);
    EXPECT_EQ(*comparison_cntr, 2);
}

TEST_F(TestFixture, BinarySearch3)
{
    ssuds::ArrayList<int> int_list = {9, 7, 5, 3, 2, 1};
    EXPECT_EQ(ssuds::binary_search(int_list, 7, ssuds::sort_type::DESCENDING), 1);
}

TEST_F(TestFixture, BinarySearch4)
{
    ssuds::ArrayList<int> int_list = {9, 7, 5, 3, 2, 1};
    long int comparison_cntr[] = {0};
    ssuds::binary_search(int_list, 7, ssuds::sort_type::DESCENDING, comparison_cntr);
    EXPECT_EQ(*comparison_cntr, 3);
}