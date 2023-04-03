#include <gtest/gtest.h>
#include <iostream>
#include <fstream>
#include <chrono>
#include <random>
#include "arraylist.h"
#include "arraylist_utility.h"
#include "linkedlist.h"
#include "delimiter_analyzer.h"
#include "queue.h"

int main(int argc, char** argv) {
    // ssuds::DelimiterAnalyzer easy1 = ssuds::DelimiterAnalyzer("test_files/easy01.lsp");
    // std::cout << easy1.process();
//     std::fstream fp("results.csv", std::ios::out);
//     std::default_random_engine generator;
//     std::uniform_int_distribution<int> distribution(0,1000);
//     fp << "SampleSize, MStime, MSops, BStime, BSops, QStime, QSops, HStime, HSops, Ltime, Lcomp, Btime, Bcomp  \n";

//     for (int z = 1000; z <= 201000; z += 1000)
//     {
//         ssuds::ArrayList<int> alist;
//         fp << z << ", ";
//         for(int i = 0; i < z; i++)
//         {
//             int dice_roll = distribution(generator); 
//             alist.append(dice_roll);
//         }
        
//         ssuds::shuffle(alist);
        
//         ssuds::ArrayList<int> acopy(alist);
//         ssuds::ArrayList<int> acopy1(alist);
//         ssuds::ArrayList<int> acopy2(alist);

//         int starting_val = acopy[0];
        
//         auto start = std::chrono::steady_clock::now();
//         long int op_countMS = 
//             ssuds::merge_sort(alist, ssuds::sort_type::ASCENDING);

//         auto end = std::chrono::steady_clock::now();

//         long int op_timeMS = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

//         start = std::chrono::steady_clock::now();
//         long long int op_countBS = 
//             ssuds::bubble_sort(acopy, ssuds::sort_type::ASCENDING);

//         end = std::chrono::steady_clock::now();

//         long int op_timeBS = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

//         long int comparison_cntrL[] = {0};
//         start = std::chrono::steady_clock::now();
//         alist.find(starting_val, 0, comparison_cntrL);
//         end = std::chrono::steady_clock::now();

//         long int op_timeL = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

//         long int comparison_cntrB[] = {0};
//         start = std::chrono::steady_clock::now();
//         ssuds::binary_search(acopy, starting_val, ssuds::sort_type::ASCENDING, comparison_cntrB);
//         end = std::chrono::steady_clock::now();

//         long int op_timeB = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

//         long int op_countQS[] = {0};
//         start = std::chrono::steady_clock::now();
//         ssuds::quicksort(acopy1, 0, acopy1.size() - 1, ssuds::sort_type::ASCENDING, op_countQS);
//         end = std::chrono::steady_clock::now();

//         long int op_timeQS = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

//         start = std::chrono::steady_clock::now();
//         long int op_countHS = ssuds::heapsort(acopy2, acopy2.size(), ssuds::sort_type::ASCENDING);
//         end = std::chrono::steady_clock::now();

//         long int op_timeHS = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();


//         fp << op_timeMS << ", " << op_countMS << ", " << op_timeBS << ", " <<
//         op_countBS << ", " << op_timeQS << ", " << *op_countQS << ", " << 
//         op_timeHS << ", " << op_countHS << ", " <<
//         op_timeL << ", " << *comparison_cntrL << ", " << op_timeB << ", " << 
//         *comparison_cntrB << "\n";

//     }


    

// return 0;
::testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
