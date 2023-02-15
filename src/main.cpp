#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include "arraylist.h"
#include "arraylist_utility.h"

int main(int argc, char** argv) {
    std::cout << "Hello, tests!\n";

    // int_list.append(1);
    // int_list.append(2);
    // int_list.append(3);
    // ssuds::ArrayList<int>::Iterator itr;
    // itr = int_list.begin();
    // while(itr != int_list.end())
    // {
    //     std::cout << *itr << std::endl;
    //     ++itr;
    // }


::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}