#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <random>
#include "arraylist.h"
#include "arraylist_utility.h"

int main(int argc, char** argv) {

    std::fstream fp("results.csv", std::ios::out);
    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(0,1000);
    fp << "SampleSize, MStime, MSops, \n";

    for (int z = 1000; z <= 201000; z += 1000)
    {
        ssuds::ArrayList<int> alist;
        fp << z << ", ";
        for(int i = 0; i < z; i++)
        {
            int dice_roll = distribution(generator); 
            alist.append(dice_roll);
        }
        
        ssuds::shuffle(alist);
        
        ssuds::ArrayList<int> acopy(alist);
        
        auto start = std::chrono::steady_clock::now();
        long int op_count2 = 
            ssuds::merge_sort(alist, ssuds::sort_type::ASCENDING);

        auto end = std::chrono::steady_clock::now();

        long int op_time2 = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

            
        fp << op_time2 << ", " << op_count2 << "\n";
        
    }

    


::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}